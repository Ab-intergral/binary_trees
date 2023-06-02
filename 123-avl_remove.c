#include "binary_trees.h"

/**
 * smallest - gets the smallest node
 * @node: tree to query
 *
 * Return: node with the smallest value
 */
static bst_t *smallest(bst_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->left == NULL)
		return (node);
	return (smallest(node->left));
}

/**
 * remove_node - removes a value from a binary search tree
 * @root: tree to query
 * @value: value of node to remove
 *
 * Return: the parent
 */
static bst_t *remove_node(bst_t **root, int value)
{
	bst_t *node = *root, *parent = NULL, **plink, *new, *src = NULL;

	while (node != NULL)
	{
		if (node->n == value)
		{
			parent = node->parent, src = parent;
			plink = parent == NULL ? root : parent->n > node->n ? &parent->left
																													: &parent->right;
			if (node->right == NULL && node->left == NULL)
				*plink = NULL;
			else if (node->right == NULL)
				*plink = node->left, node->left->parent = node->parent;
			else if (node->left == NULL)
				*plink = node->right, node->right->parent = node->parent;
			else
			{
				new = smallest(node->right);
				if (new == node->right)
					*plink = new, new->parent = node->parent, src = node->parent,
					new->left = node->left, new->left->parent = new;
				else
				{
					new->parent->left = new->right, src = new->parent;
					if (new->right)
						new->right->parent = new->parent;
					*plink = new, new->parent = parent, new->left = node->left;
					if (new->left)
						new->left->parent = new;
					new->right = node->right;
					if (new->right)
						new->right->parent = new;
				}
			}
			free(node);
			break;
		}
		node = value > node->n ? node->right : node->left;
	}
	return (src);
}

/**
 * adjust_balance_1 - Adjusts the balance of an AVL tree by \
 * rotating the unbalanced subtree.
 * @root: A pointer to the address of the root of the tree.
 * @node: A pointer to the inserted node.
 */
void adjust_balance_1(avl_t **root, avl_t *node)
{
	avl_t *cur = node, *new_root = *root;
	int balance = 0;

	while (cur != NULL)
	{
		balance = binary_tree_balance(cur);
		if (!((balance >= -1) && (balance <= 1)))
		{
			if ((balance == 2) && ((binary_tree_balance(cur->left) == 1)
				|| (binary_tree_balance(cur->left) == 0)))
			{
				new_root = binary_tree_rotate_right(cur);
			}
			else if ((balance == 2) && (binary_tree_balance(cur->left) == -1))
			{
				cur->left = binary_tree_rotate_left(cur->left);
				new_root = binary_tree_rotate_right(cur);
			}
			else if ((balance == -2) && ((binary_tree_balance(cur->right) == -1)
				|| (binary_tree_balance(cur->right) == 0)))
			{
				new_root = binary_tree_rotate_left(cur);
			}
			else if ((balance == 2) && (binary_tree_balance(cur->left) == -1))
			{
				cur->right = binary_tree_rotate_right(cur->right);
				new_root = binary_tree_rotate_left(cur);
			}
			new_root = (cur == *root ? new_root : *root);
			break;
		}
		cur = cur->parent;
	}
	*root = new_root;
}

/**
 * avl_remove -  removes a node from an AVL tree
 *		If the node to be deleted has two children,
 *		it will be replaced with its first in-order
 *		successor (not predecessor).
 *		After deletion of the desired node,
 *		the tree will be rebalanced if necessary
 * @root: a pointer to the root node of the tree for removing a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree after removing
 *	   the desired value, and after rebalancing, otherwise NULL.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *node = NULL, *new_root = root, *new_node = NULL, *parent = NULL;

	if (new_root != NULL)
	{
		(void)node;
		(void)new_node;
		parent = remove_node(&new_root, value);
		adjust_balance_1(&new_root, parent);
	}
	return (new_root);
}

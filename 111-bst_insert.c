#include "binary_trees.h"

/**
 * bst_insert -  inserts a value in a Binary Search Tree
 *		 if the address stored in tree is NULL,
 *		 the created node becomes the root node.
 *		 If the value is already present in the tree,
 *		 it will be ignored.
 *
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: returns a pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent, *tmp, *new_node;

	if (!tree)
		return (NULL);
	if (!*tree)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		parent = tmp;
		if (value > tmp->n)
			tmp = tmp->right;
		else if (value < tmp->n)
			tmp = tmp->left;
		else if (value == tmp->n)
			return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (value > parent->n)
		parent->right = new_node;
	else if (value < parent->n)
		parent->left = new_node;
	return (new_node);
}

#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree or 0 If tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		left_height = tree->left ? (1 + binary_tree_height(tree->left)) : 0;
		right_height = tree->right ? (1 + binary_tree_height(tree->right)) : 0;

		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 *		Balance = Height of left subtree – Height of right subtree.
 *
 * @tree: a pointer to the root node of the tree to measure the balance factor.
 * Return: 0 if tree is NULL or the balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
	{
		int right_height = 0, left_height = 0;

		right_height = tree->right ? (int)binary_tree_height(tree->right) : -1;
		left_height = tree->left ? (int)binary_tree_height(tree->left) : -1;

		return (left_height - (right_height));

	}
	return (0);
}

/**
 * helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound for the node that being checked.
 * @max: Upper bound for the node that being checked.
 *
 * Return: 1 if tree is NULL means its a BST
 *	   0 if its not BST
 */
int helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (helper(tree->left, min, tree->n - 1) &&
			helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *	   0 if its not a BST or tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (helper(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree
 *	   0 if tree is NULL or otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance_factor = abs(binary_tree_balance(tree));
	int is_bst = binary_tree_is_bst(tree);

	if (balance_factor < 1 && is_bst)
		return (1);
	return (0);
}

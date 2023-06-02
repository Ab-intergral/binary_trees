#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: size of the tree or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_size = 0, right_size = 0;

		left_size = tree->left ? binary_tree_size(tree->left) : 0;
		right_size = tree->right ? binary_tree_size(tree->right) : 0;

		return (left_size + right_size + 1);
	}
	return (0);
}

/**
 * helper - searches all binary tree nodes and determines
 *	    if the tree is complete by returning specific values.
 * @tree: a pointer to the root node of the tree to check.
 * @index: node index to check.
 * @size: size of the binary tree.
 *
 * Return: 0 if tree is NULL
 *	     if tree is not complete.
 *	   1 if tree is complete.
 */
int helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (helper(tree->left, (2 * index) + 1, size) &&
			helper(tree->right, (2 * index) + 2, size));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if its complete
 *	   0 if its not complete or tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t size;

		size = binary_tree_size(tree);
		return (helper(tree, 0, size));
	}
	return (0);
}

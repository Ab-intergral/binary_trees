#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree.
 *			A NULL pointer is not a leaf.
 * @tree: a pointer to the root node of the tree to count the number of leaves
 *
 * Return: If tree is NULL, the function returns 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree)
	{
		if (!tree->left && !tree->right)
			return (1);
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
	}
	return (0);
}

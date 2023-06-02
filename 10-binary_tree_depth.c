#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 * @tree: a pointer to the node to measure the depth
 * Return: depth or 0 If tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t depth = 0;

		depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;

		return (depth);
	}
	return (0);
}

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
 * helper - helps in printing values from left to right
 *	    in each binary tree level.
 * @level: level of binary tree to print.
 * @func: pointer to a function that is used to print values.
 * @tree: a pointer to the root binary tree.
 */
void helper(size_t level, const binary_tree_t *tree, void (*func)(int))
{
	if (level == 1)
		func(tree->n);
	else
	{
		helper(level - 1, tree->left, func);
		helper(level - 1, tree->right, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree
 *			    using level-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 *	  The value in the node must be passed as a parameter to this function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		size_t level, tree_levels;

		tree_levels = binary_tree_height(tree) + 1;

		for (level = 1; level <= tree_levels; level++)
			helper(level, tree, func);
	}
}

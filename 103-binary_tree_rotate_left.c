#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: a pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp = tree, *parent;

	if (!tree || !tree->right)
		return (NULL);

	parent = tree->parent;
	tree = tree->right;
	tmp->right = tree->left;
	if (tree->left)
		tree->left->parent = tmp;
	tmp->parent = tree;
	tree->left = tmp;

	if (parent)
		parent->right = tree;
	tree->parent = parent;
	return (tree);
}

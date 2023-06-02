#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate.
 *
 * Return: a pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp = tree, *parent;

	if (!tree || !tree->left)
		return (NULL);

	parent = tree->parent;
	tree = tree->left;
	tmp->left = tree->right;
	if (tree->right)
		tree->right->parent = tmp;
	tree->right = tmp;
	tmp->parent = tree;
	tree->parent = parent;
	if (parent)
		parent->left = tree;
	return (tree);
}

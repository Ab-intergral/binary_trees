#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree.
 * Return: a pointer to the node containing a value equals to value.
 *	   if tree is NULL or if nothing is found, the function will
 *	   return NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *tmp;

	if (tree && value)
	{
		tmp = (bst_t *)tree;
		while (tmp)
		{
			if (tmp->n > value)
				tmp = tmp->left;
			else if (tmp->n < value)
				tmp = tmp->right;
			else if (tmp->n == value)
				return (tmp);
		}
	}
	return (NULL);
}

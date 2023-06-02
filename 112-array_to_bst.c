#include "binary_trees.h"

/**
 * array_to_bst - builds a Binary Search Tree from an array
 *		  if a value of the array is already present
 *		  in the tree, this value will be ignored.
 * @array: a pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created BST,
 *	   or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 1;
	bst_t *root;

	if (!array)
		return (NULL);

	root = binary_tree_node(NULL, *array);

	while (i < size)
	{
		bst_insert(&root, *(array + i));
		i++;
	}
	return (root);
}

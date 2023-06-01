#include "binary_trees.h"

/**
 *binary_tree_insert_right - inserts a node as the right-child of another node
 *@parent: pointer to the parent node of the node to create
 *@value: value to put in the new node
 *Return: The returning the node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

binary_tree_t *new_node;

if (!parent)
	return (NULL);

new_node = malloc(sizeof(binary_tree_t));
if (!new_node)
	return (NULL);

new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;

if (parent->right != NULL)
{
	new_node->right = parent->right;
	parent->right->parent = new_node;
}
else
	new_node->right = NULL;

parent->right = new_node;

return (new_node);
}

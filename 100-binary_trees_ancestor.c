#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 *
 * Return: a pointer to the lowest common ancestor node of the two given
 *	   nodes or NULL if no common ancestor was found.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *) first);

	first_parent = first->parent, second_parent = second->parent;

	if (first == second_parent || !first_parent ||
			(!first_parent->parent && second_parent))
		return (binary_trees_ancestor(first, second_parent));

	else if (second == first_parent || !second_parent ||
			(!second_parent->parent && first_parent))
		return (binary_trees_ancestor(second, first_parent));

	return (binary_trees_ancestor(first_parent, second_parent));
}

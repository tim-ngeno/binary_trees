#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointert to the second node
 *
 * Return: pointer to the lowest common ancestor, or NULL otherwise
 */
binary_tree_t *binary_trees_ancestor(
	const binary_tree_t *first, const binary_tree_t *second)
{
	int depth_first, depth_second;

	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);

	if (first == NULL || second == NULL)
		return (NULL);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first != second && first != NULL && second != NULL)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((first == second) ? (binary_tree_t *)first : NULL);

}



/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the target node
 *
 * Return: Depth of tree, otherwise 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}

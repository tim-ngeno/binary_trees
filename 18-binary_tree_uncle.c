#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the target node
 *
 * Return: pointer to the uncle node, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent = node->parent;
	binary_tree_t *grandparent = node->parent->parent;

	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (grandparent->left == parent)
	{
		return (grandparent->right);
	}
	else
	{
		return (grandparent->left);
	}

	return (NULL);
}

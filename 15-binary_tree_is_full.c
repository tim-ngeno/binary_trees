#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * (every node has either 0 or 2 children)
 * @tree: pointer to the root node of target tree
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}

#include "binary_trees.h"
#include <limits.h>

/**
 * is_valid_bst - helper function to check if binary tree is valid BST
 * @node: pointer to the node of target tree
 * @min_val: holds the value of the smallest node visited
 * @max_val: holds the value of the biggest node visited
 *
 * Return: 1 if the tree is valid, 0 otherwise
 */
int is_valid_bst(const binary_tree_t *node, int min_val, int max_val)
{
	if (node != NULL)
	{
		if (node->n < min_val || node->n > max_val)
			return (0);
		return (is_valid_bst(node->left, min_val, node->n - 1) &&
			is_valid_bst(node->right, node->n + 1, max_val));
	}

	return (1);
}


/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the target tree
 *
 * Return: 1 if the tree is a valid BST, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_bst(tree, INT_MIN, INT_MAX));

}

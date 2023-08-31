#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 * @tree: pointer to the node of target tree
 *
 * Return: pointer to the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new = tree->left;
	binary_tree_t *temp = new->right;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	new->right = tree;
	tree->left = temp;

	if (temp != NULL)
	{
		temp->parent = tree;
	}

	new->parent = tree->parent;
	tree->parent = new;

	return (new);
}

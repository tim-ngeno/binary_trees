#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 * @tree: pointer to the root node of the target tree
 *
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new = tree->right;
	binary_tree_t *temp = new->left;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new->left = tree;
	tree->right = temp;

	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = new;
	new->parent = temp;

	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = new;
		temp->right = new;
	}

	return (new);
}

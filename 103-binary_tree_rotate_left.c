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
	binary_tree_t *parent = tree->parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	tree->right = new->left;
	if (new->left != NULL)
		new->left->parent = tree;

	new->left = tree;
	tree->parent = new;

	new->parent = parent;
	if (parent != NULL)
	{
		if (parent->left == tree)
			parent->left = new;
		parent->right = new;
	}

	return (new);
}

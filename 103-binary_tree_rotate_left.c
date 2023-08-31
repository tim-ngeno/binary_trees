#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 * @tree: pointer to the root node of the target tree
 *
 * Return: pointer to the new root node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new = tree->right;
	tree->right = new->left;
	if (new->left != NULL)
		new->left->parent = tree;
	new->left = tree;
	new->parent = tree->parent;
	tree->parent = new;

	return (new);
}

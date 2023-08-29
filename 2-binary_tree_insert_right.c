#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child
 * of another node
 * @parent: pointer to the target node
 * @value: value to be stored in the new node
 *
 * Return: pointer to the new node, NULL otherwise
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = parent->right;

	if (parent->right != NULL)
	{
		parent->right->parent = new;
	}

	parent->right = new;

	return (new);
}

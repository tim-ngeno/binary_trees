#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left child of another node
 * @parent: pointer to the target node
 * @value: value to be inserted in left child
 *
 * Return: pointer to the created node on success, NULL otherwise
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));

	if (new == NULL)
		return (NULL);

	new->parent = parent;
	new->n = value;
	new->left = parent->left;
	new->right = NULL;

	if (parent->left != NULL)
	{
		parent->left->parent = new;
	}

	parent->left = new;

	return (new);
}

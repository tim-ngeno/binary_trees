#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect(each
 * node has exactly 2 children and all leaf nodes are at same level)
 * @tree: pointer to the root node of the target tree
 *
 * Return: 1 on success, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left && tree->right) &&
	    binary_tree_height(tree->left) -
	    binary_tree_height(tree->right) == 0)
		return (1);

	binary_tree_is_perfect(tree->left);
	binary_tree_is_perfect(tree->right);

	return (0);

}



/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the target tree
 *
 * Return: 0 if the tree is NULL, tree height on success
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
	right = tree->right ? binary_tree_height(tree->right) + 1 : 0;

	return ((left > right) ? left : right);

}

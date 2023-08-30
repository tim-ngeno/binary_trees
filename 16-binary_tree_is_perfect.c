#include "binary_trees.h"


/**
 * is_perfect - checks if a binary tree is perfect
 * @node: current node being checked
 * @level: the level of the target node
 * @height: height of the binary tree
 *
 * Return: 1 if the binary tree is perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *node, int level, int height)
{
	if (node == NULL)
		return (1);

	if (node->left == NULL && node->right == NULL)
	{
		return (level == height);
	}

	if (node->left != NULL && node->right != NULL)
	{
		return ((is_perfect(node->left, level + 1, height)
			 && (is_perfect(node->right, level + 1, height))));
	}

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



/**
 * binary_tree_is_perfect - checks if a binary tree is perfect(each
 * node has exactly 2 children and all leaf nodes are at same level)
 * @tree: pointer to the root node of the target tree
 *
 * Return: 1 on success, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	return (is_perfect(tree, 0, height));
}

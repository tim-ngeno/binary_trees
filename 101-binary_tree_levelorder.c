#include "binary_trees.h"

/**
 * create_node - creates a new node
 * @data: value to be stored in the node
 *
 * Return: pointer to the new node
 */
node_t *create_node(binary_tree_t *data)
{
	node_t *new = malloc(sizeof(node_t));

	if (new == NULL)
		return (NULL);

	new->data = data;
	new->next = NULL;

	return (new);
}



/**
 * enqueue - enqueues a node into the queue
 * @front: element at front end of the queue
 * @rear: element at the rear end
 * @data: value of integer to be stored
 *
 * Return: void
 */
void enqueue(node_t **front, node_t **rear, binary_tree_t *data)
{
	node_t *new = create_node(data);

	if (new != NULL)
	{
		if (*rear == NULL)
		{
			*front = *rear = new;
		}
		else
		{
			(*rear)->next = new;
			*rear = new;
		}
	}
}



/**
 * dequeue - dequeues a node from the queue
 * @front: element at front end of the queue
 * @rear: element at rear end of the queue
 *
 * Return: integer stored in the queue
 */
binary_tree_t *dequeue(node_t **front, node_t **rear)
{
	node_t *temp = *front;
	binary_tree_t *data;

	if (*front == NULL)
		return (NULL);

	*front = (*front)->next;
	if (*front == NULL)
		*rear = NULL;

	data = temp->data;
	free(temp);
	return (data);
}



/**
 * binary_tree_levelorder - traverses a binary tree using levelorder
 * @tree: pointer to the root node of the tree
 * @func: function pointer
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	node_t *front = NULL;
	node_t *rear = NULL;
	binary_tree_t *current;

	if (tree == NULL || func == NULL)
		return;

	enqueue(&front, &rear, (binary_tree_t *)tree);

	while (front != NULL)
	{
		current = dequeue(&front, &rear);
		func(current->n);

		if (current->left != NULL)
			enqueue(&front, &rear, current->left);

		if (current->right != NULL)
			enqueue(&front, &rear, current->right);
	}
}

#include "binary_trees.h"

/**
 * create_node - creates a new node
 * @data: the value to be stored in the new node
 *
 * Return: pointer to the new node, or NULL
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
 * @front: pointer to the element at the front of the queue
 * @rear: pointer to the element at the rear end of the queue
 * @data: value stored in the node
 *
 * Return: data to be added to the queue
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
 * @front: points to the element at front of the queue
 * @rear: points to the element at the rear of the queue
 *
 * Return: data dequeued, or NULL on failure
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
 * binary_tree_is_complete - checks if a binary tree is complete
 * (one in which every level, except possibly the last, is completely filled)
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	node_t *front = NULL, *rear = NULL;
	binary_tree_t *current;

	if (tree == NULL)
		return (0);

	enqueue(&front, &rear, (binary_tree_t *)tree);

	while (front != NULL)
	{
		current = dequeue(&front, &rear);
		if (current == NULL)
		{
			while (front != NULL)
			{
				current = dequeue(&front, &rear);
				if (current != NULL)
					return (0);
			}
			return (1);
		}

		enqueue(&front, &rear, current->left);
		enqueue(&front, &rear, current->right);
	}

	return (0);
}

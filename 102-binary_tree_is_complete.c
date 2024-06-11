#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Adds a node to the end of the queue
 * @queue: Double pointer to the queue
 * @node: Pointer to the binary tree node to add
 */
void enqueue(queue_node_t **queue, const binary_tree_t *node)
{
	queue_node_t *new_node, *temp;

	if (node == NULL)
		return;

	new_node = malloc(sizeof(queue_node_t));
	if (new_node == NULL)
		return;

	new_node->node = node;
	new_node->next = NULL;

	if (*queue == NULL)
	{
		*queue = new_node;
	}
	else
	{
		temp = *queue;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

/**
 * dequeue - Removes a node from the front of the queue
 * @queue: Double pointer to the queue
 *
 * Return: Pointer to the binary tree node removed from the queue
 */
const binary_tree_t *dequeue(queue_node_t **queue)
{
	queue_node_t *temp;
	const binary_tree_t *node;

	if (queue == NULL || *queue == NULL)
		return (NULL);

	temp = *queue;
	node = temp->node;
	*queue = (*queue)->next;
	free(temp);

	return (node);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_node_t *queue = NULL;
	const binary_tree_t *current;
	int found_null = 0;

	if (tree == NULL)
		return (0);

	enqueue(&queue, tree);

	while ((current = dequeue(&queue)) != NULL)
	{
		if (current->left)
		{
			if (found_null)
				return (0);
			enqueue(&queue, current->left);
		}
		else
		{
			found_null = 1;
		}
		if (current->right)
		{
			if (found_null)
				return (0);
			enqueue(&queue, current->right);
		}
		else
		{
			found_null = 1;
		}
	}

	return (1);
}

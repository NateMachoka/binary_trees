#include "binary_trees.h"
#include "queue.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
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

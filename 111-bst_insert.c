#include "binary_trees.h"

/**
 * bst_insert - inserts a value into a binary search tree
 * @tree: double pointer to the root node of the bst
 * @value: value to insert
 *
 * Return: pointer to the newly-inserted node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent, *current;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	current = (*tree);
	parent = NULL;

	while (current != NULL)
	{
		parent = current;

		if (value == current->n)
			return (NULL);
		if (value < current->n)
			current = current->left;
		if (value > current->n)
			current = current->right;
	}
	new_node = binary_tree_node(parent, value);

	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (new_node);
}

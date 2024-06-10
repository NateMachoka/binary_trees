#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right child of another one
 * @parent: a pointer to the node to insert the right-child in
 * @value: data to store in the new node
 * Return: Pointer to the new node, NULL is parent is NULL or on failure
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	new_node->right = parent->right;

	if (parent->right != NULL)
		parent->right->parent = new_node;

	parent->right = new_node;

	return (new_node);
}

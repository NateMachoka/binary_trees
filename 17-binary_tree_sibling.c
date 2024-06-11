#include "binary_trees.h"

/**
 * binary_tree_sibling - checks if node has a sibling
 * @node: pointer to the node to find the sibling
 *
 * Return: pointer to the sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	if (node == node->parent->right)
		return (node->parent->left);

	return (NULL);
}

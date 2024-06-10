#include "binary_trees.h"

/**
 * binary_tree_depth - depth of a node in a binary tree
 * @tree: pointer to a a node to measure depth
 *
 * Return: depth of the node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t node_depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent != NULL)
	{
		node_depth++;
		tree = tree->parent;
	}
	return (node_depth);
}

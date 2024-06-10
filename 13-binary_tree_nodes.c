#include "binary_trees.h"

/**
 * binary_tree_nodes - counts number of nodes with at least one child
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: number of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL || tree->right != NULL)
		return(binary_tree_nodes(tree->left) + binary_tree_nodes
		       (tree->right) + 1);

	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}

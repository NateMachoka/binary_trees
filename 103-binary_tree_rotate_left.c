#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_rotate_left - rotates binary tree to the left
 * @tree: pointer to the root node of the tree
 *
 * Return: pointer to the new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left != NULL)
		new_root->left->parent = tree;

	if (tree->parent != NULL)
	{
		if (tree == tree->parent->left)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}
	new_root->left = tree;
	tree->parent = new_root;

	return (new_root);
}

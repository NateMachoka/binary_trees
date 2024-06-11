#include "binary_trees.h"
#include <limits.h>

/**
 * max - Returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 *
 * Return: Maximum of a and b
 */
int max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * height - Computes the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
int height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + max(height(tree->left), height(tree->right)));
}

/**
 * is_bst_helper - Helper function to check if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum value for the node's data
 * @max: Maximum value for the node's data
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid bst
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_avl_helper - Helper function to check if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the tree to check
 * @height: Pointer to an integer to store the height of the tree
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int *height)
{
	int left_height = 0, right_height = 0;
	int left_is_avl, right_is_avl;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}
	left_is_avl = is_avl_helper(tree->left, &left_height);
	right_is_avl = is_avl_helper(tree->right, &right_height);

	*height = 1 + max(left_height, right_height);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (left_is_avl && right_is_avl);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
		return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	return (is_avl_helper(tree, &height));
}

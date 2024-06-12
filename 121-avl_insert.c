#include "binary_trees.h"

avl_t *avl_insert(avl_t **tree, int value);
avl_t *insert_avl_node(avl_t *node, int value, avl_t **created_node);
avl_t *balance_tree(avl_t *node);

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of the AVL tree to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *created_node = NULL;

	if (tree == NULL)
		return (NULL);

	*tree = insert_avl_node(*tree, value, &created_node);
	return (created_node);
}

/**
 * insert_avl_node - Helper function to insert a node in an AVL tree
 * @node: Pointer to the root node of the subtree
 * @value: Value to store in the node to be inserted
 * @created_node: Double pointer to the node created
 *
 * Return: Pointer to the new root of the subtree after insertion
 */
avl_t *insert_avl_node(avl_t *node, int value, avl_t **created_node)
{
	if (node == NULL)
	{
		*created_node = binary_tree_node(NULL, value);
		return (*created_node);
	}

	if (value < node->n)
	{
		node->left = insert_avl_node(node->left, value, created_node);
		if (node->left != NULL)
			node->left->parent = node;
	}
	else if (value > node->n)
	{
		node->right = insert_avl_node(node->right, value, created_node);
		if (node->right != NULL)
			node->right->parent = node;
	}
	else
	{
		*created_node = NULL;
		return (node);
	}

	return (balance_tree(node));
}

/**
 * balance_tree - Balances an AVL tree
 * @node: Pointer to the root node of the subtree to balance
 *
 * Return: Pointer to the new root of the subtree after balancing
 */
avl_t *balance_tree(avl_t *node)
{
	int balance_factor = binary_tree_balance(node);

	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}

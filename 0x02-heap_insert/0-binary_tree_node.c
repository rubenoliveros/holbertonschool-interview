#include "binary_trees.h"

/**
* binary_tree_node - Insert the node at given parent.
*
* @parent: Pointer to the parent node.
* @value: Integer value in the new node.
* Return: The inserted node.
*/

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;

	return (node);
}

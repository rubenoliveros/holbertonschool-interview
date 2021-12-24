#include "binary_trees.h"

/**
 * is_perfect_binary_tree - check if the tree is perfect.
 * @count: number of nodes.
 * Return: 1 if is perfect, otherwise 0.
 */
int is_perfect_binary_tree(int count)
{
	count = count + 1;
	while (count % 2 == 0)
		count = count / 2;

	if (count == 1)
		return (1);
	else
		return (0);
}
/**
 * binary_tree_size - size of the tree
 * @tree: root of the treee
 * Return: size
 */
size_t binary_tree_size(heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * binary_tree_insert - add a binary tree node in level order
 * @root: parent node
 * @node: node to insert
 * Return: pointer to the root of modified tree.
 */
heap_t *binary_tree_insert(heap_t *root, heap_t *node)
{
	size_t r_count, l_count;

	if (root == NULL)
	{
		root = node;
		node->parent = root;
		return (node);
	}

	r_count = binary_tree_size(root->right);
	l_count = binary_tree_size(root->left);
	if (r_count == 0 && l_count == 0)
	{
		root->left = node;
		node->parent = root;
		return (root);
	}
	else if (r_count == 0 && l_count == 1)
	{
		root->right = node;
		node->parent = root;
		return (root);
	}
	else if (r_count == l_count)
		root->left = binary_tree_insert(root->left, node);
	else if (r_count < l_count)
	{
		if (is_perfect_binary_tree(l_count))
			root->right = binary_tree_insert(root->right, node);
		else
			root->left = binary_tree_insert(root->left, node);
	}
	return (root);
}

/**
* heap_insert - Insert the node to a binary heap.
*
* @root: Pointer to the parent node.
* @value: Integer value in the new node.
* Return: The inserted node.
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int swap;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	*root = binary_tree_insert(*root, new_node);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = swap;
		new_node = new_node->parent;
	}
	return (new_node);
}

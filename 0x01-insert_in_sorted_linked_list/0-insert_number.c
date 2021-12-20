#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

 /**
  * insert_node - Adds a new node.
  * @head: Pointer of the first node.
  * @number: Number to insert.
  * Return: The address of the new node, or NULL if it failed.
  */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL || head == NULL)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		if (current->n > new->n)
		{
			new->next = current;
			*head = new;
			return (*head);
		}
		else
		{
			while (current->next != NULL && current->next->n < new->n)
			{
				current = current->next;
			}
			new->next = current->next;
			current->next = new;
			return (new);
		}
	}
}

#include "shell.h"

/**
 * list_len- list length
 * @h: singly linked list.
 * Return: The number of nodes.
 */

size_t list_len(const list_t *h)
{
	size_t elem;

	elem = 0;
	while (h != NULL)
	{
		h = h->next;
		elem++;
	}
	return (elem);
}

/**
 * add_node- adds new node to linked list
 *
 * @head: a pointer to the head of the linked list
 * @str: name of node
 *
 * Return: address of new node.
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (!new)
		return (0);
	new->str = strdup(str);
	new->len = strlen(str);
	new->next = *head;
	*head = new;
	return (*head);
}

/**
 * add_node_end - adds a new node at the end
 * of a list_t list.
 * @head: head of the linked list.
 * @str: string to store in the list.
 * Return: address of the head.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *temp;
	size_t nchar;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = _strdup((char *)str);

	for (nchar = 0; str[nchar]; nchar++);

	new->len = nchar;
	new->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}

	return (*head);
}

/**
 * free_list - free the memory allocated to a linked list
 * @head: a double pointer to a linked list
 * Return: nothing
 */
void free_list(list_t *head)
{
	list_t *current, *next;

	current = head;

	while (!current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}

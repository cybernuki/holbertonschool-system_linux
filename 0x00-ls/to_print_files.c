#include "./to_print_files.h"

/**
 * add_node_files - adds a node in a double linked list at the end
 * @head: head of the list
 * @value: value of the node
 * Return: a pointer to the new node
 */
to_print_files *add_node_files(to_print_files **head, char *value)
{
	to_print_files *new =  NULL, *index = (*head);

	if (!value)
		return (NULL);

	new = (to_print_files *) malloc(sizeof(to_print_files));
	if (!new)
		return (NULL);

	new->value = value;
	new->prev = NULL;
	new->next = NULL;

	if (!*head)
	{
		*head = new;
		return (new);
	}

	while (index->next)
		index = index->next;

	new->prev = index;
	index->next = new;

	return (new);
}

/**
 * free_list_files - Free a double linked list
 * @head: head of the list
 * Return: nothing
 */
void free_list_files(to_print_files *head)
{
	to_print_files *tmp = NULL;

	if (head)
	{
		while (head->next)
			head =  head->next;

		while (head)
		{
			tmp = head->prev;
			free(head);
			head = tmp;
		}
	}
}

/**
 * remove_node_files - removes a node in a given position
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int remove_node_files(to_print_files **head, unsigned int index)
{
	to_print_files *actual;
	size_t size;

	actual = *head;
	size = 0;
	if (*head == NULL)
		return (-1);
	while (actual != NULL)
	{
		size++;
		actual = actual->next;
	}
	if (size < index + 1)
		return (-1);
	actual = *head;
	if (index == 0)
	{
		*head = actual->next;
		if (actual->next)
			actual->next->prev = NULL;
		actual->next = NULL;
		free(actual);
		return (1);
	}
	while (index--)
		actual = actual->next;
	actual->prev->next = actual->next;
	if (actual->next)
		actual->next->prev = actual->prev;
	free(actual);
	return (1);
}

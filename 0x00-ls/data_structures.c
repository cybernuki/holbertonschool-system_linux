#include "./headers/data_structures.h"


to_print *add_node(to_print **head, struct dirent *value) {
	to_print *new =  NULL, *index = (*head);

	if (!value)
		return NULL;

	new = (to_print *) malloc(sizeof(to_print));
	if (!new)
		return NULL;

	new->value = value;
	new->prev = NULL;
	new->next = NULL;

	if (!*head) {
		*head = new;
		return (new);
	}

	while (index->next)
		index = index->next;

	new->prev = index;
	index->next = new;

	return (new);
}

void free_list(to_print *head) {
	to_print *tmp = NULL;

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

int remove_node(to_print **head, unsigned int index) {
	to_print *actual;
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
};

void print_list(const to_print *h) {
	int size = 0;

	while (h)
	{
		printf("%s ", h->value->d_name);
		size++;
		h = h->next;
	}
	printf("\n");
}

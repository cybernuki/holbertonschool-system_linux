#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct dlistint_s
{
	struct dirent *value;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} to_print;


to_print *add_node(to_print **head, struct dirent *value);

int remove_node(to_print **head, unsigned int index);

void free_list(to_print *head);

void sort_list(to_print *list);


void print_list(const to_print *h);
#endif

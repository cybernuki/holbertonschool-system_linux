#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

/**
 * struct dlistint_s - doubly linked list
 * @value: dirent value
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


/**
 * add_node - adds a node in a double linked list at the end
 * @head: head of the list
 * @value: value of the node
 * Return: a pointer to the new node
 */
to_print *add_node(to_print **head, struct dirent *value);

/**
 * remove_node - removes a node in a given position
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int remove_node(to_print **head, unsigned int index);

/**
 * free_list - Free a double linked list
 * @head: head of the list
 * Return: nothing
 */
void free_list(to_print *head);

/**
 * sort_list - sort the linked list in place
 * @head: is the head of the list
 * @by: the criterio to be sorted, it could be 'S' to sort by size
 * 't' to sort by time or, 'r' to reverse the list
 */
void sort_list(to_print **head, char by, char order);


void print_list(const to_print *h);
#endif

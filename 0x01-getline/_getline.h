#ifndef GETLINE_H
#define GETLINE_H

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define READ_SIZE 1024

/**
 * struct _lines_struct - simple linked list that represents
 * each line of the file
 * @content: the content of the line
 * @next: points to the next node
 * @size: size of the content
 * Description: singly linked list node structure
 */
typedef struct _lines_struct
{
	char *content;
	struct _lines_struct *next;
	int size;
} lines;

/**
 * struct _fd_list - simple linked list that represents
 * data from a file descriptor
 * @fd: the file descriptor
 * @current_line: the current line
 * @lines: the simple linked list with the value for each line
 * @next: is the next node in the list
 *
 * Description: singly linked list node structure
 */
typedef struct _fd_list
{
	int fd;
	int current_line;
	lines *lines;
	struct _fd_list *next;
} fd_list;

/**
 * add_line_node - creates a new line node and set its values
 *
 * Return: a new line node
 */
lines *add_line_node();

/**
 * parser - reads the file descriptor and creates the
 * line list filter by \\n character
 *
 * @fd: is the file descriptor
 * Return: a lines list with each line on the file
 */
lines *parser(int fd);

/**
 * close_struct - close a fd_list
 * @files: is the list of files
 */
void close_struct(fd_list *files);

/**
 * add_node - add a new node of list of files
 * @fd: is the file descriptor
 * @head: is the head of the list of files
 * Return: the new node created
 */
fd_list *add_node(const int fd, fd_list **head);

/**
 * get_line - It takes the first line on the list of files
 * @node: is the node that have the line
 * Return: the content of the line struct
 */
char *get_line(fd_list *node);

/**
 * _getline - returns a line from a file
 * @fd: is the file descriptor
 * Return: the string of the line or NULL in case of error or EOF
 */
char *_getline(const int fd);
#endif

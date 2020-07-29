#include "_getline.h"

/**
 * add_line_node - creates a new line node and set its values
 *
 * Return: a new line node
 */
lines *add_line_node()
{
	lines *new = NULL;

	new = (lines *)malloc(sizeof(lines));
	new->next = NULL;
	new->content = malloc(sizeof(char) * 1024);
	memset(new->content, 0, READ_SIZE);

	return (new);
}

/**
 * parser - reads the file descriptor and creates the
 * line list filter by \\n character
 *
 * @fd: is the file descriptor
 * Return: a lines list with each line on the file
 */
lines *parser(int fd)
{
	lines *head = NULL, *current = NULL;
	char *tmp, buf[READ_SIZE];
	size_t i = 0, s = 0, readed = 0;

	head = add_line_node();
	current = head;

	readed = read(fd, buf, READ_SIZE);
	while (readed)
	{
		for (i = 0, s = 0; i < readed; i++)
		{
			if (buf[i] == '\n')
			{
				tmp = malloc(sizeof(char) * 1024);
				memset(tmp, 0, 1024);
				tmp = strncpy(tmp, &buf[s], (i - s));
				strcat(current->content, tmp);
				s = i + 1;
				current->next = add_line_node();
				current = current->next;
				free(tmp);
			}
			else if (i == (readed - 1) && buf[i] != '\n')
			{
				tmp = malloc(sizeof(char) * 1024);
				memset(tmp, 0, 1024);
				tmp = strncpy(tmp, &buf[s], (i - s + 1));
				strcat(current->content, tmp);
				free(tmp);
			}
		}
		memset(buf, 0, READ_SIZE);
		readed = read(fd, buf, READ_SIZE);
	}
	return (head);
}

/**
 * close_struct - close a fd_list
 * @files: is the list of files
 */
void close_struct(fd_list *files)
{
	fd_list *next = NULL;
	lines *line = NULL, *nline = NULL;

	if (!files)
		return;
	while (files)
	{
		next = files->next;
		line = files->lines;
		while (line)
		{
			nline = line->next;
			free(line);
			line = nline;
		}
		free(files);
		files = next;
	}
}

/**
 * add_node - add a new node of list of files
 * @fd: is the file descriptor
 * @head: is the head of the list of files
 * Return: the new node created
 */
fd_list *add_node(const int fd, fd_list **head)
{
	fd_list *new = NULL, *index = *head;

	new = malloc(sizeof(fd_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->current_line = 0;
	new->lines = NULL;
	new->next = NULL;
	if (!index)
	{
		new->lines = parser(fd);
		(*head) = new;
	}
	else
	{
		while (index)
		{
			if (index->fd == fd)
			{
				close_struct(new);
				return (index);
			}
			if (index->next)
				index = index->next;
			else
				break;
		}
		new->lines = parser(fd);
		index->next = new;
	}
	return (new);
}

/**
 * get_line - It takes the first line on the list of files
 * @node: is the node that have the line
 * Return: the content of the line struct
 */
char *get_line(fd_list *node)
{
	lines *line = NULL;
	char *content = NULL;

	if (!node)
		return (NULL);
	line = node->lines;
	if (!line)
		return (NULL);
	content = line->content;
	node->lines = node->lines->next;
	free(line);
	return (content);
}

/**
 * _getline - returns a line from a file
 * @fd: is the file descriptor
 * Return: the string of the line or NULL in case of error or EOF
 */
char *_getline(const int fd)
{
	static fd_list *files;
	fd_list *current = NULL;
	char *content = NULL, *buff = NULL;
	int size = 0;

	if (fd == -1)
	{
		close_struct(files);
		files = NULL;
		return (NULL);
	}
	current = add_node(fd, &files);
	content = get_line(current);

	if (!content)
		return (NULL);
	for (size = 0; content[size]; size++)
		;
	buff = (char *)malloc(size + 1);
	memset(buff, 0, size + 1);
	strncpy(buff, content, size + 1);
	free(content);
	return (buff);
}

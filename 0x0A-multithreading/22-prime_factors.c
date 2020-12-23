#include "multithreading.h"

/**
 * create_task - create a new task
 * @entry: is the given entry function
 * @param: is the param
 * Return: a new Task or NULL on failure
 */
task_t *create_task(task_entry_t entry, void *param)
{
	task_t *task = NULL;

	task = calloc(1, sizeof(*task));
	if (!task)
		return (NULL);
	task->entry = entry;
	task->param = param;
	task->status = PENDING;
	return (task);
}

/**
 * destroy_task - destroy a task
 * @task: is the given task
 */
void destroy_task(task_t *task)
{
	if (task->result)
	{
		list_destroy((list_t *)task->result, free);
		free((list_t *)task->result);
	}
	free(task);
}

/**
 * exec_tasks - execute tasks
 * @tasks: given tasks
 * Return: smenthing
 */
void *exec_tasks(list_t const *tasks)
{
	node_t *index = tasks->head;
	int i = 0;
	task_t *task = NULL;

	while (index)
	{
		task = (task_t *)index->content;
		if (task->status == PENDING)
		{
			task->status = STARTED;
			tprintf("[%02d] Started\n", i);
			task->result = (void *)(((list_t * (*)(char const *)) task->entry)((char const *)task->param));
			tprintf("[%02d] Success\n", i);

			task->status = task->result ? SUCCESS : FAILURE;
		}
		i++;
		index = index->next;
	}
	return NULL;
}

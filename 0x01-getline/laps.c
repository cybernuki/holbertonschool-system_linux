#include "./laps.h"

hash_table_t *hash_table_create(unsigned long int size)
{
	unsigned long int i = 0;
	hash_table_t *table = NULL;

	table = malloc(sizeof(hash_table_t));
	if (!table)
	{
		return (NULL);
	}

	table->array = malloc(sizeof(table->array) * size);
	if (!table->array)
	{
		free(table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		table->array[i] = NULL;
	table->size = size;
	return (table);
}

unsigned long int key_index(int key, unsigned long int size)
{
	unsigned long int hash;

	if (!key)
		return (0);
	hash = 5381;
	hash = ((hash << 5) + hash) + key;
	return (hash % size);
}

int hash_table_set(hash_table_t *ht, int key)
{
	hash_node_t *new_node = NULL, *node = NULL;
	unsigned long int index;

	if (!ht)
		return (0);

	index = key_index(key, ht->size);
	node = ht->array[index];
	while (node)
	{
		if (node->key == key)
		{
			node->value += 1;
			return (1);
		}
		node = node->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (!new_node)
		return (0);
	new_node->key = key;
	new_node->value = 0;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	printf("Car %d joined the race\n", key);
	return (1);
}

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node = NULL, *next = NULL;
	size_t i;

	if (ht)
	{
		for (i = 0; i < ht->size; i++)
		{
			node = ht->array[i];
			while (node)
			{
				next = node->next;
				free(node);
				node = next;
			}
		}
		free(ht->array);
		free(ht);
	}
}

void race_state(int *id, size_t size)
{
	static int started;
	size_t i;
	static hash_table_t *table;
	hash_node_t *node = NULL;
	int key = 0, laps = 0;

	if (!started)
	{
		table = hash_table_create(1024);
		started = 1;
	}
	if (!size)
		hash_table_delete(table);
	else
	{
		for (i = 0; i < size; i++)
			hash_table_set(table, id[i]);
		printf("Race state:\n");
		for (i = 0; i < table->size; i++)
		{
			node = table->array[i];
			while (node)
			{
				key = node->key;
				laps = node->value;
				printf("Car %d [%d laps]\n", key, laps);
				node = node->next;
			}
		}
	}
}

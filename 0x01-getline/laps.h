#ifndef LAPS_H
#define LAPS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct hash_node_s - Node of a hash table
 *
 * @key: The key, string
 * The key is unique in the HashTable
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the List
 */
typedef struct hash_node_s
{
	int key;
	int value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 *
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell of this array is a pointer to the first node of a linked list,
 * because we want our HashTable to use a Chaining collision handling
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/**
 * hash_table_create - initialize and hash table
 * @size: the size of the new table
 * Return: a new table or null if somenthing went wrong
 */
hash_table_t *hash_table_create(unsigned long int size);

/**
 * hash_table_delete - deletes a hash table
 * @ht: is the hash table
 * Return: nothing
 */
void hash_table_delete(hash_table_t *ht);

/**
 * hash_table_set - adds an element to the hash table
 * @ht: is the hash table
 * @key: is the key to be added
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, int key);

/**
 * key_index - Returns the index at which the key/value pair should be stored
 * in the array of the hash table
 * @key: is the string key
 * @size: is the size of the table
 * Return: The key index
 */
unsigned long int key_index(int key, unsigned long int size);

/**
 * race_state - This function keeps track of the number of the laps
 * made by several cars in a race
 * @id: isan array of int representing the "identifier" of each car
 * @size: is the size of this array
 */
void race_state(int *id, size_t size);
#endif

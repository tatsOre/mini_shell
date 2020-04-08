#include "simple_shell.h"
/**
 * _add_directory - Adds each PATH directory to a linked list
 * @path: Complete list of PATH directories
 * @path_directory: each directory contained in the the env variable PATH
 * Return: Address of the new element
 */

path_dir *_add_directory(path_dir **path, char *path_directory)
{
	path_dir *new;

	new = malloc(sizeof(path_dir));

	if (new == NULL)
		return (NULL);

	new->dir = _strdup(path_directory);
	new->next = NULL;

	if (*path == NULL)
	{
		*path = new;
		return (*path);
	}

	while ((*path)->next != NULL)
		path = &(*path)->next;

	(*path)->next = new;

	return (new);
}

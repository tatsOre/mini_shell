#include "simple_shell.h"

/**
 * _free_list - function that frees a path_dir list
 * @list: first node of the list
 * Return: Nothing
 */

void _free_list(path_dir *list)
{
	path_dir *tmp;

	if (list == NULL)
		return;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->dir);
		free(tmp);
	}
}

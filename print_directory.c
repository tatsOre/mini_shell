#include "simple_shell.h"

/**
 * print_directories - Function that prints all the elements of a PATH directory
 * @path: PATH directory
 * Return: Nothing
 */

void print_directories(const path_dir *path)
{

	while (path != NULL)
	{
		printf("%s\n", path->dir);
		path = path->next;
	}

}

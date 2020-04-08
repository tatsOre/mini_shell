#include "simple_shell.h"

/**
 * _path_list - Adds each PATH directory to a linked list
 * @path_env_variable: Complete list of PATH directories
 * Return: Address of the PATH linked list
 */

path_dir *path_list(char *path_env_variable)
{
	path_dir *pathlist;
	char *directory;

	pathlist = NULL;

	directory = strtok(path_env_variable, ":");

	while (directory != NULL)
	{
		_add_directory(&pathlist, directory);
		directory = strtok(NULL, ":");
	}

	return (pathlist);
}

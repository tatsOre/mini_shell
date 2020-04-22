#include "simple_shell.h"

/**
 * main - FUNCTION UNDER CONSTRUCTION - Get the full path for a program file
 * in this file, the extern environ variable is used. Is in the unistd.h lib.
 * return - Nothing
 */
char *_getfilepath(char *cmd)
{
	char *filepathname = NULL;
	path_dir *path_directories;
	char *path;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (cmd);
	else
	{
		path = _getenv("PATH");

		path_directories = path_list(path);

		while (path_directories != NULL)
		{
			filepathname = _path_concat(path_directories->dir, cmd);

			if (stat(filepathname, &st) == 0)
			{
				return (filepathname);
			}
			path_directories = path_directories->next;
		}
	}

	return (cmd);
}

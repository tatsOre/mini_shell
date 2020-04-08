#include "simple_shell.h"

/**
 * _getenv - Obtains the string value of a specified environment variable
 * @name: environment variable to obtain
 * Return: pointer to string value
 */

char *_getenv(char *name)
{
	int index = 0;

	while (environ[index])
	{
		if (_strncmp(environ[index], name, _strlen(name)) == 0)
			break;
		++index;
	}

	return (environ[index]);
}

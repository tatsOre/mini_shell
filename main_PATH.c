#include "simple_shell.h"

/**
 * main - prints the enviroment in different ways
 * in this file, the extern environ variable is used. Is in the unistd.h lib.
 * return - Nothing
 */

int main(int ac, char **av, char **env)
{
	int index = 0;
	char *env_variable;

/* lista de directorios de la env var PATH */
	path_dir *path;

	(void)ac;
	(void)av;

/* segment of code that will print env vars with environ global var */
/*
	printf("***Environment variables (environ global variable):\n");

	index = 0;

	while (environ[index])
	{
		printf("envp[%d]: %s\n", index, environ[index]);
		++index;
	}

	printf("***The address of the environ var is %p:\n", (void *)&environ);
	printf("***The address of the main env var is %p:\n", (void *)&env);
	printf("=============\n");
	printf("***Environment variables (env *third main arg*):\n");
/* segment of code that will print env vars with main env var */
/*	index = 0;

	while (env[index])
        {
                printf("main env var[%d]: %s\n", index, env[index]);
                ++index;
        }
/* segment of code that will search por a variable name in environ arr and will return it */
	printf("=========================\n");
	env_variable = getenv("PATH");
	printf("PATH variable with getenv = %s, checking length = %d\n", env_variable, 88);

	printf("=========================\n");
/*

	env_variable = _getenv("PATH");
	printf("***Address of env_variable %p\n", (void *)&env_variable);
	printf("PATH variable with _getenv = %s, checking length = %d\n", env_variable, 88);
	printf("=========================\n");
/*
	env_variable = _getenv("USER");
        printf("your USER is = %s\n", env_variable); */
/* segment of code that pretends save in a linked list all the PATH directories and print them */
	printf("******Printing Struc Directories ******************\n");

	path = path_list(env_variable);
	print_directories(path);

	print_directories(path);

/* Freeing structures and variables */
/*	free_list(path);  */
	return (0);
}

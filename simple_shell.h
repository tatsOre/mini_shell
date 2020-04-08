#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#define _GNU_SOURCE
#define DELIMITER " \n"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/**
 * struct path_directories - singly linked list
 * @dir: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: PATH env var directories
 */

typedef struct path_directories
{
	char *dir;
	struct path_directories *next;
} path_dir;


/* Main Functions */
char **_parser(char *line);
int execute_cmd(char **args, char **env);


/* String Handling Functions */
int _strlen(char *str);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_str_concat(char *str1, char *str2);

/* Path Handling Functions */
char *_getenv(char *name);
path_dir *path_list(char *path_env_variable);
path_dir *_add_directory(path_dir **path, char *path_directory);
void free_list(path_dir *list);

/* Demo functions */
void _print_directories(const path_dir *path);
char *_path_concat(char *path, char *command);
char *_getfilepath(char *cmd);

#endif /* SIMPLE_SHELL_H */

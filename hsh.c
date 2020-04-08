#include "simple_shell.h"

int main(int ac, char **av, char **env)
{
        char *input = NULL, **tokens;
        size_t length = 0;
        int read;
/* int status */
/*	signal(SIGINT, hsin); what is it? */

	(void)ac;
	(void)av;

	signal(SIGINT, SIG_DFL); /*check this crap */

        do {
                printf("$ ");
		read = getline(&input, &length, stdin);
                tokens = _parser(input);
                execute_cmd(tokens, env);
		/*	status = _executer(tokens, env); */

        } while (read);

	free(input);
        free(tokens);

	return (0);
}

int execute_cmd(char **args, char **env)
{
	struct stat st;
	pid_t child_pid;
	int status;
	char *filepath = NULL;

	filepath = _getfilepath(args[0]);

	if (stat(filepath, &st) == 0)
	{
		child_pid = fork();

	       	if (child_pid == -1)
       		{
			printf("Error:");
			return (EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			execve(filepath, args, env);
			printf("Command: %s\n", args[0]);
			return (EXIT_FAILURE); /*this cannot be return Failure */
		}
		else
		{
			wait(&status);
		}
	}
	else
	{
		printf("Command not found: %s\n", args[0]);
	}

	return (EXIT_FAILURE);
}

char *_getfilepath(char *cmd)
{
	char *filepathname = NULL, *path = NULL;
	path_dir *path_directories;
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


char **_parser(char *line)
{
	int buffsize = 64, index = 0;
	char **tokens, *token;

	tokens = malloc(buffsize * sizeof(char *));

	if (tokens == NULL)
	{
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIMITER);

	while (token != NULL)
	{
 		tokens[index] = token;
		index++;

		token = strtok(NULL, DELIMITER);
	}

	tokens[index] = NULL;

	return (tokens);
}

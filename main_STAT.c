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
	char *full;
/* lista de directorios de la env var PATH */

        path_dir *path;
	char *file_path;


        (void)ac;
        (void)av;

        printf("=======path_concat========\n");

        full = _path_concat("/bin", "ls");
        printf("_PATH_CONCAT FUNC = %s\n", full);

	printf("========fixing bug pathfile name =============\n");
/* file path */

	file_path = _getfilepath("ls");

	printf("El resultado de file_path  1 = %s\n", file_path);

	file_path = _getfilepath("ls");

	printf("El resultado de file_path ahora es  2 = %s\n", file_path);

	file_path = _getfilepath("ls");

	printf("El resultado de file_path ahora es  3 = %s\n", file_path);

        return (0);
}

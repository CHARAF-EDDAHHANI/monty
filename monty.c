#include "monty.h"


/**
 * main - entry point
 * @ac: number of arguments
 * @av: array of arguments
 * Return: 0 on success
*/
int main(int ac, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	global.line = NULL;
	global.file = NULL;
	global.stack = NULL;
	global.line_number = 0;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(av[1], "r");
	if (global.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	global.file = global.file;

	while ((read = getline(&line, &len, global.file)) != -1)
	{
		global.line_number++;

		global.line = split(line, " \n\t\r");
		if (global.line != NULL && global.line[0] != NULL)
			get_op_func(global.line[0])(&global.stack, global.line_number);

		free(global.line);
	}

	free(line);
	free_all(global.stack, global.file);
	return (EXIT_SUCCESS);
}

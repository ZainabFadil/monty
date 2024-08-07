#include "monty.h"

/**
* read_file - read_file from args
* @argv: argv passed by user
* Return: exit code
*/
int read_file(char **argv)
{
	char *filename = argv[1];
	char *input, ***lines;
	char file_lines[(BUFFER_SIZE * 10) + 1];
	int exit_code = EXIT_SUCCESS, input_data_size, fd;

	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		input_data_size = read(fd, file_lines, BUFFER_SIZE * 10);
		if (input_data_size > 0)
		{
			input = malloc(input_data_size + 1);
			if (input != NULL)
			{
				file_lines[input_data_size] = '\0';
				strcpy(input, file_lines);
				lines = get_lines(input);
				if (lines != NULL)
				{
					exit_code = interpret_lines(lines);
				}
				free(input);
			}
			else
			{
				print_monty_error(MALLOC_FAIL, 0);
				exit_code = EXIT_FAILURE;
			}
		}
		close(fd);
	}
	else
	{
		print_monty_error(FILE_NOT_OPEN, 1, filename);
		exit_code = EXIT_FAILURE;
	}
	return (exit_code);
}

#include "monty.h"
shared_t shared_value = {0, 0};

/**
 * handle_push_param - handle_push_param
 * @line: line
 * @line_number: line_number
 * Return: exit code
*/
int handle_push_param(char **line, unsigned int line_number)
{
	int *value;
	int exit_code = EXIT_SUCCESS;

	if (line != NULL && line[1] != NULL)
	{
		value = string_to_integer(line[1]);
		if (value == NULL || *line[1] == ' '
			|| *line[1] == '\0' || isspace(*line[1]))
		{
			print_monty_error(INVALID_INT, 1, (int)line_number);
			exit_code = EXIT_FAILURE;
			free(value);
		}
		else
		{
			shared_value.n = *value;
			free(value);
		}
	}
	else
	{
		print_monty_error(INVALID_INT, 1, (int)line_number);
		exit_code = EXIT_FAILURE;
	}
	return (exit_code);
}
/**
 * process_line - process_line
 * @stack: stack
 * @line: line
 * @line_number: line_number
 * Return: int
*/
int process_line(stack_t **stack, char **line, unsigned int line_number)
{
	int exit_code = EXIT_SUCCESS;
	int opcode_index = 0, is_handeled_opcode = 0;
	char *opcode;
	instruction_t instructions[] = { {"push", push},
	{"pall", pall}, {"pint", pint}, {"pop", pop},
	{"nop", nop}, {"swap", swap}, {"add", add},
	{"sub", sub}, {"mul", mul}, {"div", _div},
	{"mod", mod}, {"pchar", pchar}, {"pstr", pstr},
	{NULL, NULL}
	};

	if (line != NULL)
	{
		opcode = line[0];
		if (strcmp(opcode, "push") == 0)
		{
			exit_code = handle_push_param(line, line_number);
			if (exit_code != EXIT_SUCCESS)
			{
				return (exit_code);
			}
		}
		while (instructions[opcode_index].opcode != NULL)
		{
			if (strcmp(opcode, instructions[opcode_index].opcode) == 0)
			{
				instructions[opcode_index].f(stack, line_number);
				is_handeled_opcode = 1;
				break;
			}
			opcode_index++;
		}
		if (!is_handeled_opcode && *line[0] != '#')
		{
			print_monty_error(INVALID_OPCODE, 2, (int)line_number, opcode);
			exit_code = EXIT_FAILURE;
		}
	}
	return (exit_code);
}


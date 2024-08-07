#include "monty.h"
/**
 * free_all_lines - frees the lines that executed by program
 * @lines: the pointers that will be freed
 * Return: void
*/
void free_all_lines(char ***lines)
{
	char ***temp = NULL;
	char **inner = NULL;
	char **temp_inner = NULL;

	if (lines == NULL)
		return;

	temp = lines;
	while (*temp != NULL)
	{
		inner = *temp;
		if (inner != NULL)
		{
			temp_inner = inner;
			while (*temp_inner != NULL)
			{
				free(*temp_inner);
				temp_inner++;
			}
			free(inner);
		}
		temp++;
	}
	free(lines);
}

/**
 * free_lines - pointer to 2d pointers array
 * @lines: the matrix that will be freed
 * @row_index: index of the row
 * Return: Void
*/
void free_lines(char ***lines, int row_index)
{
	int i = 0;

	for (i = 0; i < row_index; i++)
	{
		free(lines[i]);
	}
	free(lines);
	lines = NULL;
}

/**
 * free_stack - free_stack
 * @stack: stack
*/
void free_stack(stack_t **stack)
{
	stack_t *node = *stack;
	stack_t *tmp = NULL;

	while (node != NULL)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(stack);
	*stack = NULL;
}

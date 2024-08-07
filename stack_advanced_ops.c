#include "monty.h"


/**
* _div - _div
* @stack: stack
* @line_number: line_number
*/
void _div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_DIV_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;

		if (temp_first->n == 0)
		{
			free_stack(stack);
			print_monty_error(DIV_BY_ZERO, 1, (int)line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			int result = temp_second->n / temp_first->n;

			pop(stack, line_number);
			(*stack)->n = result;
		}
	}
}
/**
* mul - mul
* @stack: stack
* @line_number: line_number
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_MUL_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;
		int result = temp_second->n * temp_first->n;

		pop(stack, line_number);
		(*stack)->n = result;
	}
}
/**
* mod - mod
* @stack: stack
* @line_number: line_number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_MOD_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;

		if (temp_first->n == 0)
		{
			free_stack(stack);
			print_monty_error(DIV_BY_ZERO, 1, (int)line_number);
			exit(EXIT_FAILURE);
		}
		else
		{
			int result = temp_second->n % temp_first->n;

			pop(stack, line_number);
			(*stack)->n = result;
		}
	}
}

/**
 * pchar - pchar
 * @stack: stack
 * @line_number: line_number
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		print_monty_error(INVALID_PTCHR, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		int head_value = (*stack)->n;

		if (head_value >= 0 && head_value <= 127)
		{
			char str[20];

			sprintf(str, "%c\n", head_value);
			write(STDOUT_FILENO, str, strlen(str));
		}
		else
		{
			print_monty_error(INVALID_ASCII, 1, (int)line_number);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pstr - pstr
 * @stack: stack
 * @line_number: line_number
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack == NULL)
	{
		putchar('\n');
	}
	else
	{
		stack_t *head = *stack;
		char str[20];

		do {
			if (head != NULL)
			{
				sprintf(str, "%c", head->n);
				write(STDOUT_FILENO, str, strlen(str));
				head = head->next;
			}
		} while (head != NULL &&
					head->n > 0 && head->n <= 127);
		putchar('\n');
	}
}

#include "monty.h"

/**
* push - push
* @stack: stack
* @line_number: line_number
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = create_node(shared_value.n);

	(void) line_number;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
/**
* pall - pall
* @stack: stack
* @line_number: line_number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	if (*stack != NULL)
	{
		stack_t *head = *stack;

		do {
			if (head != NULL)
			{
				char str[20];

				sprintf(str, "%d\n", head->n);
				write(STDOUT_FILENO, str, strlen(str));
				head = head->next;
			}
		} while (head != NULL);
	}
}
/**
* pint - pint
* @stack: stack
* @line_number: line_number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		print_monty_error(EMPTY_STACK, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *top = *stack;
		char str[20];

		sprintf(str, "%d\n", top->n);
		write(STDOUT_FILENO, str, strlen(str));
	}
}
/**
* pop - pop
* @stack: stack
* @line_number: line_number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		print_monty_error(POP_EMPTY_STACK, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *head = *stack;
		*stack = head->next;
		if (*stack != NULL)
		{
			(*stack)->prev = NULL;
		}
		free(head);
	}
}

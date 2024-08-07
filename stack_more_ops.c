#include "monty.h"
/**
* swap - swap
* @stack: stack
* @line_number: line_number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(INVALID_SWAP, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;

		temp_first->next = temp_second->next;
		temp_first->prev = temp_second;
		temp_second->next = temp_first;
		temp_second->prev = NULL;

		if (temp_first->next != NULL)
		{
			temp_first->next->prev = temp_first;
		}
		*stack = temp_second;
	}
}
/**
* add - add
* @stack: stack
* @line_number: line_number
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_ADD_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;
		int result = temp_first->n + temp_second->n;

		pop(stack, line_number);
		(*stack)->n = result;
	}
}
/**
* nop - nop
* @stack: stack
* @line_number: line_number
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
* sub - sub
* @stack: stack
* @line_number: line_number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free_stack(stack);
		print_monty_error(FEW_SUB_NODES, 1, (int)line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *temp_first = *stack;
		stack_t *temp_second = (*stack)->next;
		int result = temp_second->n - temp_first->n;

		pop(stack, line_number);
		(*stack)->n = result;
	}
}

#include "monty.h"

/**
 * initialize_empty_stack - initialize_empty_stack
 * Return: pointer to pointer for sttack_t struct
*/
stack_t **initialize_empty_stack()
{
	stack_t **stack = malloc(sizeof(stack_t *));

	if (stack == NULL)
	{
		print_monty_error(MALLOC_FAIL, 0);
		exit(EXIT_FAILURE);
	}
	else
	{
		*stack = NULL;
	}
	return (stack);
}

/**
* create_node - create_node
* @n: n
* Return: new node
*/
stack_t *create_node(int n)
{
	stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		print_monty_error(MALLOC_FAIL, 0);
		exit(EXIT_FAILURE);
	}
	else
	{
		new_node->n = n;
		new_node->next = NULL;
		new_node->prev = NULL;
		return (new_node);
	}
}

/**
* get_top_node - get_top_node
* @stack: stack
* Return: pointer to top node
*/
stack_t *get_top_node(stack_t *stack)
{
	stack_t *top = NULL;
	stack_t *current = NULL;

	if (stack != NULL)
	{
		current = stack;
		while (current->next != NULL)
		{
			current = current->next;
		}
		top = current;
	}
	return (top);
}

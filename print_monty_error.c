#include "monty.h"

const MONTY_ERORR monty_errors[] = {
	{USAGE, "USAGE: monty file\n"},
	{FILE_NOT_OPEN, "Error: Can't open file %s\n"},
	{MALLOC_FAIL, "Error: malloc failed\n"},
	{INVALID_INT, "L%d: usage: push integer\n"},
	{INVALID_OPCODE, "L%d: unknown instruction %s\n"},
	{EMPTY_STACK, "L%d: can't pint, stack empty\n"},
	{POP_EMPTY_STACK, "L%d: can't pop an empty stack\n"},
	{INVALID_SWAP, "L%d: can't swap, stack too short\n"},
	{FEW_ADD_NODES, "L%d: can't add, stack too short\n"},
	{FEW_SUB_NODES, "L%d: can't sub, stack too short\n"},
	{FEW_MUL_NODES, "L%d: can't mul, stack too short\n"},
	{FEW_DIV_NODES, "L%d: can't div, stack too short\n"},
	{FEW_MOD_NODES, "L%d: can't mod, stack too short\n"},
	{DIV_BY_ZERO, "L%d: division by zero\n"},
	{INVALID_PTCHR, "L%d: can't pchar, stack empty\n"},
	{INVALID_ASCII, "L%d: can't pchar, value out of range\n"}
};


/**
 * process_monty_error - processes errors of the monty
 * @error_code: object that identify the error type
 * @ptr: pointer
 * Return: nothing (Void)
*/
void process_monty_error(enum ERROR_CODE error_code, va_list ptr)
{
	char *original_message = malloc(150);
	char *error_message = malloc(150);
	int char_index = 0, length = 0;
	char *ptr_to_replace = NULL;
	int int_value;

	if (original_message != NULL && error_message != NULL)
	{
		memset(error_message, 0, 150);
		strcpy(original_message, monty_errors[error_code].message);

		while (original_message[char_index] != '\0')
		{
			if (original_message[char_index] == '%')
			{
				if (original_message[char_index + 1] == 's')
				{
					ptr_to_replace = va_arg(ptr, char *);
				}
				else if (original_message[char_index + 1] == 'd')
				{
					int_value = va_arg(ptr, int);
					ptr_to_replace = int_to_string(int_value);
				}
				error_message = strcat(error_message, ptr_to_replace);
				char_index += 2;
			}
			else if (original_message[char_index] != '%')
			{
				length = strlen(error_message);
				error_message[length] = original_message[char_index];
				char_index++;
			}
		}
		va_end(ptr);
		write(STDERR_FILENO, error_message, strlen(error_message));
		free(error_message);
		free(original_message);
	}
}


/**
* print_monty_error - dynamic print for error msg based on the error code
* @error_code: enum for monty_error codes
* @ptr_num: number of passed pointers to the function
* Return: void (No return value)
*/
void print_monty_error(enum ERROR_CODE error_code, int ptr_num, ...)
{
	va_list ptr;

	if ((int)error_code >= 0 && (int)error_code < MAX_CODE)
	{
		if (ptr_num > 0)
		{
			va_start(ptr, ptr_num);
			process_monty_error(error_code, ptr);
			va_end(ptr);
			return;
		}
		else
		{
			write(STDERR_FILENO, monty_errors[error_code].message,
				  strlen(monty_errors[error_code].message));
		}
	}
}

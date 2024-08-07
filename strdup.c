#include "monty.h"

/**
 * str_dup - str_dup
 * @s: s
 * Return: string
*/
char *str_dup(const char *s)
{
	char *new_str = malloc(strlen(s) + 1);

	if (new_str != NULL)
	{
		strcpy(new_str, s);
	}
	return (new_str);
}

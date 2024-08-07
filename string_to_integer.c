#include "monty.h"

/**
* string_to_integer - converts the string to an integer to
* handles the arguments of command
* @s: string that will be converted
* Return: converted integer
*/
int *string_to_integer(char *s)
{
int val = 0;
int i = 0;
int *ret = malloc(sizeof(int));

if (s[0] == '-')
{
	i = 1;
}

	for (; s[i] != '\0'; i++)

	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			val *= 10;
			val += (s[i] - '0');
		}
		else
		{
			free(ret);
			return (NULL);
		}
	}
	*ret = val;
	if (s[0] == '-')
	{
		*ret = val * -1;
	}
return (ret);
}

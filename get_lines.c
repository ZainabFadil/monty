#include "monty.h"
/**
 * remove_leading_traling_space - removes the trailing white spaces in input
 * @str: input command of the user
 * Return: (void) cleans string
*/
void remove_leading_traling_space(char *str)
{
	int i, j;
	int length = 0;

	if (str != NULL)
	{
		length = strlen(str);
		i = 0;
		while (str[i] == ' ')
		{
			i++;
		}
		if (i > 0)
		{
			for (j = 0; j < length - i + 1; j++)
			{
				str[j] = str[j + i];
			}
		}
		length = strlen(str);
		i = length - 1;
		if (i >= 0)
		{
		while (str[i] == ' ')
		{
			str[i] = '\0';
			i--;
		}
		}
	}
}

/**
 * get_rows_count - counts the rows of the 2d array
 * @input: input array
 * Return: int (num of the rows)
*/
size_t get_rows_count(char *input)
{
	size_t rows_count = 0;
	char *rows_token;
	char *temp_input = str_dup(input);

	if (temp_input != NULL)
	{
	remove_leading_traling_space(temp_input);
	if (temp_input != NULL && strlen(temp_input) > 0)
	{
	rows_token = strtok(temp_input, "\n");
	while (rows_token != NULL)
	{
		rows_count++;
		rows_token = strtok(NULL, "\n");
	}
	}
	free(temp_input);
	}
	shared_value.rows_count = rows_count;
	return (rows_count);
}

/**
 * get_columns_count_by_row_index - caluclate the index of the column
 * @input: the input array
 * @row_index: index of the row
 * Return: int (column count)
*/
size_t get_columns_count_by_row_index(char *input, size_t row_index)
{
	size_t column_count = 0;
	char *token;
	size_t current_row = 0;
	char *copy_input = str_dup(input);

	if (copy_input != NULL)
	{
	token = strtok(copy_input, "\n");
	while (token != NULL && current_row < row_index)
	{
		token = strtok(NULL, "\n");
		current_row++;
	}
	if (token != NULL)
	{
		token = strtok(token, " \t");
		while (token != NULL)
		{
			column_count++;
			token = strtok(NULL, " \t");
		}
	}
	free(copy_input);
	}
	return (column_count);
}

/**
 * get_substring_by_indexes - get substrings to handle the commands
 * @input: input string the user entred
 * @row_index: index of the row
 * @column_index: index of the column
 * Return: string (command of the user after processinf function)
*/
char *get_substring_by_indexes(char *input, size_t row_index,
								size_t column_index)
{
	size_t current_row = 0, current_column = 0;
	char *substring = NULL;
	char *row_token, *row_copy;
	char *column_token;
	char *copy_input = str_dup(input);

	row_token = strtok(copy_input, "\n");
	while (row_token != NULL && current_row < row_index)
	{
		row_token = strtok(NULL, "\n");
		current_row++;
	}
	if (row_token != NULL)
	{
		row_copy = str_dup(row_token);
		column_token = strtok(row_copy, " \t");
		current_column = 0;
		while (column_token != NULL && current_column < column_index)
		{
			column_token = strtok(NULL, " \t");
			current_column++;
		}
		if (column_token != NULL)
		{
			substring = str_dup(column_token);
		}
		free(row_copy);
	}

	if (copy_input != NULL)
		free(copy_input);
	return (substring);
}

/**
* get_lines - extract the commands the user entered
* @file_conent_ptr: pointer to content entered in the shell
* Return: 2 dimensional array of all commands lines
*/
char ***get_lines(char *file_conent_ptr)
{
	char  ***argv = NULL, *file_conent_ptr_copy = str_dup(file_conent_ptr);
	size_t rows_count = 0, columns_count = 0, row_index, column_index = 0;

	if (file_conent_ptr_copy != NULL)
	{
		rows_count = get_rows_count(file_conent_ptr_copy);
		if (rows_count > 0)
		{
		argv = (char ***)malloc((rows_count + 1) * sizeof(char **));
		if (argv != NULL)
		{
			for (row_index = 0; row_index < rows_count ; row_index++)
			{
				columns_count = get_columns_count_by_row_index
									(file_conent_ptr_copy, row_index);
				argv[row_index] = malloc(((columns_count + 1) * sizeof(char *)));
				if (argv[row_index] != NULL)
				{
					for (column_index = 0; column_index < columns_count; column_index++)
					{
						argv[row_index][column_index] = get_substring_by_indexes
														(file_conent_ptr_copy, row_index, column_index);
					}
					argv[row_index][columns_count] = NULL;
				}
				else
				{
					free_lines(argv, row_index);
					break;
				}
			}
			if (argv != NULL)
			{
				argv[rows_count] = NULL;
			}
		}
	}
	free(file_conent_ptr_copy);
	}
	return (argv);
}

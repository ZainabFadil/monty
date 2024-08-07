#ifndef _monty_
#define _monty_
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
/**
 * enum ERROR_CODE - enum that contains the error code that appears for user
 * @USAGE: wrong USAGE
 * @FILE_NOT_OPEN: FILE_NOT_OPEN
 * @MALLOC_FAIL: MALLOC_FAIL
 * @INVALID_INT: INVALID_INT
 * @INVALID_OPCODE: INVALID_OPCODE
 * @POP_EMPTY_STACK: POP_EMPTY_STACK
 * @EMPTY_STACK: EMPTY_STACK
 * @INVALID_SWAP: INVALID_SWAP
 * @FEW_ADD_NODES: FEW_ADD_NODES
 * @FEW_SUB_NODES: FEW_SUB_NODES
 * @FEW_MUL_NODES: FEW_MUL_NODES
 * @FEW_DIV_NODES: FEW_DIV_NODES
 * @FEW_MOD_NODES: FEW_MOD_NODES
 * @DIV_BY_ZERO: DIV BY ZERO
 * @INVALID_PTCHR: INVALID_PTCHR
 * @INVALID_ASCII: invalid asci
 * @MAX_CODE: MAX_CODE
 *
 * Description: error codes that will be appear to the user in the monty
*/
typedef enum ERROR_CODE
{
	USAGE = 0,
	FILE_NOT_OPEN = 1,
	MALLOC_FAIL = 2,
	INVALID_INT = 3,
	INVALID_OPCODE = 4,
	EMPTY_STACK = 5,
	POP_EMPTY_STACK = 6,
	INVALID_SWAP = 7,
	FEW_ADD_NODES = 8,
	FEW_SUB_NODES = 9,
	FEW_MUL_NODES = 10,
	FEW_DIV_NODES = 11,
	FEW_MOD_NODES = 12,
	DIV_BY_ZERO = 13,
	INVALID_PTCHR = 14,
	INVALID_ASCII = 15,
	MAX_CODE
} ERROR_CODE;

/**
* struct MONTY_ERORR - struct that contains all MONTY ERORR TYPES
* @code: index of the error code starts from 0
* @message: the content of error message
* Description: MONTY ERORR TYPES
*/
typedef struct MONTY_ERORR
{
	enum ERROR_CODE code;
	char *message;
} MONTY_ERORR;

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
* @rows_count: rows_count
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
		int n;
		int rows_count;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;


/**
* struct shared - shared data
* @n: integer
* @rows_count: rows_count
*
* Description: shared
*/
typedef struct shared
{
		int n;
		int rows_count;
} shared_t;

extern shared_t shared_value;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
		char *opcode;

		void (*f)(stack_t **stack, unsigned int line_number);

} instruction_t;
/**stack operations*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
/**helpers*/
char *int_to_string(int number);
int *string_to_integer(char *s);
char *str_dup(const char *s);
int read_file(char **argv);
char ***get_lines(char *file_conent_ptr);
int interpret_lines(char ***lines);
int handle_push_param(char **line, unsigned int line_number);
int process_line(stack_t **stack, char **line, unsigned int line_number);
int interpret_lines(char ***lines);
void free_lines(char ***lines, int row_index);
void free_all_lines(char ***lines);
void print_monty_error(enum ERROR_CODE error_code, int ptr_num, ...);
/**stack helper*/
stack_t **initialize_empty_stack();
stack_t *create_node(int n);
stack_t *get_top_node(stack_t *stack);
void free_stack(stack_t **stack);
#endif

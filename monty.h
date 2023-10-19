#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - a doubly linked list representation 
 * of a stack (or queue).
 * @n: integer number.
 * @prev: points to the previous element of a stack (or queue).
 * @next: points to the next element of a stack (or queue).
 *
 * Description: doubly linked list node structure.
 * for stack, queues, LIFO, FIFO Holberton project.
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content.
 * @arg: value.
 * @file: pointer to monty file.
 * @content: line content.
 * @lifi: flag change stack <-> queue.
 * Description: carries values through the program.
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function.
 * @opcode: the opcode.
 * @f: function to handle the opcode.
 *
 * Description: opcode and its function.
 * for stack, queues, LIFO, FIFO Holberton project.
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * _realloc - the function  Reallocates a memory block using malloc and free.
 * @ptr: a Pointer to the memory previously allocated.
 * @old_size: the Size, in bytes, of the allocated space for ptr.
 * @new_size: a New size, in bytes of the new memory block.
 *
 * Return: return Pointer to the newly allocated memory, or NULL if it fails.
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
/**
 * getstdin - the function Reads an entire line from stdin, 
 * storing the address of the buffer containing the text into *lineptr
 * @lineptr: If *lineptr is NULL, then getstdin will allocate 
 * a buffer for storing a line. 
 * This buffer should be freed by the user program.
 * @file: File descriptor
 *
 * Return: return The number of characters read, 
 * including the delimiter character, but not including 
 * the terminating null byte. Or -1 on failure to 
 * read a line (including end-of-file condition).
 */
ssize_t getstdin(char **lineptr, int file);
/**
 * clean_line - the function Cleans up the content line
 * @content: the Line content to be cleaned
 *
 * Return: return Cleaned up line content
 */
char  *clean_line(char *content);
/**
* f_push - the function Pushes an element to the stack.
* @head: a Double pointer to the head of the stack.
* @number: the Number to push onto the stack.
*/
void f_push(stack_t **head, unsigned int number);
/**
* f_pall - the function Prints all values on the stack,
* starting from the top of the stack.
* @head: a Double pointer to head of stack.
* @number: the Unused parameter.
*/
void f_pall(stack_t **head, unsigned int number);
/**
 * f_pint - the function Prints the value at 
 * the top of the stack, followed by a new line.
 * @head: Double pointer to head of stack.
 * @number: Unused parameter.
 */
void f_pint(stack_t **head, unsigned int number);
/**
 * execute - the function Executes a opcode function.
 * @content: Line content will be executed.
 * @head: Double pointer will head of stack.
 * @counter: a Line number for error handling.
 * @file: a File pointer for error handling.
 * Return: return 0 on success, 1 on failure.
 */
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
/**
 * free_stack - the function Frees a stack_t stack.
 * @head: a Pointer to head of stack.
 */
void free_stack(stack_t *head);

/**
 * f_pop - the function Removes the top element of the stack.
 * @head: a Double pointer to head of stack.
 * @counter: the Line number for error handling.
 */
void f_pop(stack_t **head, unsigned int counter);
/**
 * f_swap - the function Swaps the top two elements of the stack.
 * @head: a Double pointer to head of stack.
 * @counter: the Line number for error handling.
 */
void f_swap(stack_t **head, unsigned int counter);
/**
 * f_add - the function Adds the top two elements of the stack.
 * @head: a Double pointer to head of stack.
 * @counter: the Line number for error handling.
 */
void f_add(stack_t **head, unsigned int counter);
/**
 * f_nop - the function Doesn’t do anything.
 * @head: a Double pointer to head of stack.
 * @counter: Unused parameter,never used inside its body.
 */
void f_nop(stack_t **head, unsigned int counter);
/**
 * f_sub - the function Subtracts the top element of the 
 * stack from the second top element of the stack.
 * @head: a Double pointer to head of stack.
 * @counter: the Line number for error handling.
 */
void f_sub(stack_t **head, unsigned int counter);
/**
 * f_div - the function Divides the second top 
 * element of the stack by the top element of the stack.
 * @head: a Double pointer to head of stack.
 * @counter: the Line number for error handling.
 */
void f_div(stack_t **head, unsigned int counter);
/**
 * f_mul - the function Multiplies the second top element 
 * of the stack with the top element of the stack.
 * @head: a Double pointer to head of stack.
 * @counter: the Line number for error handling.
 */
void f_mul(stack_t **head, unsigned int counter);
/**
 * f_mod - the function Computes the remainder of the division 
 * of the second top element of the stack by the top element of the stack.
 * @head: Double pointer to head of stack.
 * @counter: Line number for error handling.
 */
void f_mod(stack_t **head, unsigned int counter);
/**
 * f_pchar - the function Prints the char at the top of 
 * the stack, followed by a new line.
 * @head: Double pointer to head of stack.
 * @counter: Line number for error handling.
 */
void f_pchar(stack_t **head, unsigned int counter);
/**
 * f_pstr - the function Prints the string starting 
 * at the top of the stack, followed by a new line.
 * @head: Double pointer to head of stack.
 * @counter: Unused parameter,never used inside its body.
 */
void f_pstr(stack_t **head, unsigned int counter);
/**
 * f_rotl - the function Rotates the stack to the top. 
 * The top element of the stack becomes the last one, 
 * and the second top element becomes the first one
 * @head: a Double pointer to head of stack.
 * @counter: Unused parameter,never used inside its body.
 */
void f_rotl(stack_t **head, unsigned int counter);
/**
 * f_rotr - the function Rotates the stack to the bottom. The last element becomes 
 * the top one, and all other elements are shifted down one position
 * @head: a Double pointer to head of stack.
 * @counter: the Unused parameter due to attribute specification
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
/**
 * addnode - the function Adds a new node at the beginning of a dlistint_t list
 * @head: the Double pointer to head of list
 * @n: a Value to be added in new node
 */
void addnode(stack_t **head, int n);
/**
 * addqueue - the function Adds a new node at end of a dlistint_t list
 * @head: a Double pointer to head of list
 * @n: a Value to be added in new node
 */
void addqueue(stack_t **head, int n);
/**
* f_queue - the function Changes behavior from 'stack' (LIFO) to 'queue' (FIFO)
* @head: a Double pointer to head of list
* @counter: the Line number for error handling
*/
void f_queue(stack_t **head, unsigned int counter);
/**
* f_stack - the function Changes behavior from 'queue' (FIFO) to 'stack' (LIFO)
* @head: a Double pointer to head of list
* @counter: the Line number for error handling
*/
void f_stack(stack_t **head, unsigned int counter);
#endif


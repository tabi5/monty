#include "monty.h"

/**
 * f_rotr - function Rotates the stack to the bottom.
 * @stack_head: the double pointer to the head of the stack.
 * @counter: a line number for error
 * reporting in case of usage errors.
 * function rotates the stack to the bottom. The last element
 * of the stack becomes the first one,
 * and the second last element becomes
 * the last one. This function does nothing if the stack contains less
 * than two elements.
 *
 * Return: return This function does not return a value.
 */
void f_rotr(stack_t **stack_head, __attribute__((unused)) unsigned int counter)
{
	stack_t *l_node;
	unsigned int rot_count = counter;

	l_node = *stack_head;
	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	while (l_node->next)
	{
		l_node = l_node->next;
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		rot_count++;
	}
	l_node->next = *stack_head;
	l_node->prev->next = NULL;
	l_node->prev = NULL;
	(*stack_head)->prev = l_node;
	(*stack_head) = l_node;
	counter = rot_count;
	printf("Number of rotations: %d\n", counter);
}

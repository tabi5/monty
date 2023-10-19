#include "monty.h"

/**
  * f_rotl - Rotates the stack to the top.
  * @stack_head: A double pointer to the head of the stack.
  * @counter: The line number for error
  * reporting in case of usage errors.
  *
  * Description: This function rotates the
  * stack to the top. The top element
  * of the stack becomes the last one,
  * and the second top element becomes
  * the first one. This function does nothing
  * if the stack contains less
  * than two elements.
  *
  * Return: return This function does not return a value.
  */
void f_rotl(stack_t **stack_head, __attribute__((unused)) unsigned int counter)
{

	stack_t *cur_node = *stack_head, *ne_node;
	unsigned int rot_count = counter;
	unsigned int line_number = counter;

	if (*stack_head == NULL || (*stack_head)->next == NULL)
	{
		return;
	}
	ne_node = (*stack_head)->next;
	ne_node->prev = NULL;
	while (cur_node->next != NULL)
	{
		cur_node = cur_node->next;
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		rot_count++;
	}
	cur_node->next = *stack_head;
	(*stack_head)->next = NULL;
	(*stack_head)->prev = cur_node;
	(*stack_head) = ne_node;
	counter = rot_count;
	printf("Number of rotations: %d\n", counter);
}

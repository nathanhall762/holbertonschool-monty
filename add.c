#include "monty.h"

/**
 * add - adds first two nodes of a stack
 * @stack: stack given
 * @line_number: line counter
 *
 * Return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	sum = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_number);
	(*stack)->n = sum;
}

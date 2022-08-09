#include "monty.h"

/**
 * add - 
 * @stack:
 * @line_cnt:
 *
 * Return: void
 */

void _add(stack_t **stack, unsigned int line_cnt)
{
	int sum;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf("L<line_number>: can't add, stack too short\n", line_cnt);
		exit(EXIT_FAILURE);
		return;
	}

	sum = ((*stack)->next->n) + ((*stack)->n);
	pop(stack, line_cnt);
	(*stack)->n = sum;
}

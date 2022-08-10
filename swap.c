#include "monty.h"

/**
 * swap - swaps first two nodes in a stack_t list
 * @stack: pointer to stack
 * @line_number: line number of .m file where opcode occurs
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !(*stack)->next->n)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

#include "monty.h"

/**
 * swap - swaps first two nodes in a stack_t list
 * @stack: pointer to stack
 * @line_number: line number of .m file where opcode occurs
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int tmp_n = 0;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	tmp = *stack;
	tmp_n = tmp->n;
	tmp->n = tmp_n;
	tmp->n = tmp->next->n;
	tmp->next->n = tmp_n;
}

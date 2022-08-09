#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: stack that is given
 * @line_cnt: line counter
 *
 * Return: void
 */

void _pint(stack_t **stack, unsigned int line_cnt)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L<line_number>: can't pint, stack empty\n", line_cnt);
		status = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
}

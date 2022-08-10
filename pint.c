#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: stack that is given
 * @line_number: line counter
 *
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%d\n", (*stack)->n);
}

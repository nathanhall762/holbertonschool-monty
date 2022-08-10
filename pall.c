#include "monty.h"

/**
 * pall - print stack_t.n from beginning to end of stack_t list
 * @stack: pointer to stack
 * @line_number: line number of .m file where opcode occurs
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int len = 0;

	(void) line_number;

		while (*stack != NULL)
		{
			printf("%d\n", (*stack)->n);
			++len;
			*stack = (*stack)->next;
		}
}

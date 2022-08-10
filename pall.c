#include "monty.h"

/**
 * pall - print stack_t.n from beginning to end of stack_t list
 * @stack: pointer to stack
 * @line_number: line number of .m file where opcode occurs
 */
void pall(stack_t **stack, unsigned int line_number)
{
	int len = 0;
	stack_t *temp;

	temp = *stack;
	(void) line_number;

	while (temp != NULL)
	{
		printf("%d\n", (temp)->n);
		++len;
		temp = (temp)->next;
	}
}

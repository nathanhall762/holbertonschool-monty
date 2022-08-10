#include "monty.h"

/**
 * pop - removes top element from the stack
 * @stack: pointer to stack to remove element from
 * @line_number: line number of error message
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;

	if ((*stack)->next != NULL)
		(*stack)->next->prev = NULL;
	free(*stack);
	(*stack) = temp;
}

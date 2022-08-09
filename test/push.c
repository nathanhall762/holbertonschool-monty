#include "header.h"

/**
 * push - adds new node at beginning of stack_t list
 * @stack: pointer to stack
 * @line_number: line number of .m file where opcode occurs
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *arg = Arg.argument;
	int data, i;
	stack_t *element;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i] != '\0'; i++)
	{
		if ((isdigit(arg[i])) == 0 && arg[i] != '-')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}

	data = atoi(arg);

	element = malloc(sizeof(stack_t));
	if (element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	element->n = data;
	element->prev = NULL;
	element->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = element;
	}
	*stack = element;
}

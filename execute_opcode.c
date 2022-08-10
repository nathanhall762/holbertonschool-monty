#include "monty.h"

/**
 * execute_opcode - compare opcode to opcode array and call matching function
 * @opcode: opcode passed to function
 * @stack: pointer to stack
 * @line_number: line number of .m file where opcode occurs
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	/* initialize i and instruction_t with opcodes */
	int i = 0;
	instruction_t opcodes[] = OPCODES;

	/* loop */
	while (opcodes[i].opcode)
	{
		/* string compare opcode with instruction_t list of opcodes */
		if (strcmp(opcodes[i].opcode, opcode) == 0)
		{
			/* call function pointer in instruction_t list if match */
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}

	/* print error if nothing is called */
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);

	/* exit */
	exit(EXIT_FAILURE);
}

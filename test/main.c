#include "header.h"

int main(int argc, char **argv)
{
	/* declare variables */
	FILE *fd;
	char *line = NULL;
	size_t size = 0;
	char *opcode = NULL;
	unsigned int line_number = 1; /* Monty starts counting lines at 1 */
	stack_t *STACK, *temp;
	(void) argc; /* temporary */

	STACK = NULL;

	/* open file */
	fd = fopen(argv[1], "r");

	/* error if cannot open file - maybe using fprintf */
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file\n");
		exit(EXIT_FAILURE);
	}


	/* read each line of function in a loop while tracking line number for error purposes */
	while ((getline(&line, &size, fd)) != (-1))
	{
		/* check for blank line */
		if (*line == '\n')
		{
			line_number++;
			continue;
		}
		/* set opcode to first token of strtok */
		opcode = strtok(line, " \t\n");

		/* check for strtok fail */
		if (!opcode)
		{
			line_number++;
			continue;
		}
		/* set argument to second token of strtok */
		Arg.argument = strtok(NULL, " \t\n");

		/* do the thing - execute_opcode */
		execute_opcode(opcode, &STACK, line_number);
		line_number++;
	}

	/* free line */
	free(line);

	/* free stack */
	if (STACK != NULL)
	{
		while (STACK != NULL)
		{
			temp = STACK;
			STACK = temp->next;
			free(temp);
		}
	}
	/* close file */
	fclose(fd);

	/* exit */
	exit(EXIT_SUCCESS);
}

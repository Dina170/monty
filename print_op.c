#include "monty.h"

/**
 * pall - print all nodes
 * @head: head of linked list
 * @line_number: number of interpreted line
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	(void) line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print top value
 * @head: head of linked list
 * @line_number: number of interpreted line
 */
void pint(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

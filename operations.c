#include "monty.h"

/**
 * isInteger - checks if string is integer
 * @str: pointer to string
 *
 * Return: 1 is true, 0 if not
 */
char isInteger(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}

/**
 * _push - add int to the top of the stack
 * @head: head of linked list
 * @line_number: number of interpreted line
 */

void _push(stack_t **head, unsigned int line_number)
{
	int n;
	char *secArg;
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	secArg = strtok(NULL, " \n");
	if (!secArg || !isInteger(secArg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(secArg);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}

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



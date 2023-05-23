#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @head: head of linked list
 * @line_number: number of interpreted line
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	*head = tmp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: A pointer to the head of the dlistint_t.
 * @line_number: number of interpreted line
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;
	int swap_tmp;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	swap_tmp = tmp->n ^ tmp->next->n;
	tmp->n = tmp->n ^ swap_tmp;
	tmp->next->n = tmp->next->n ^ swap_tmp;
}

/**
 * add - adds the top two elements of the stack
 * @head: A pointer to the head of the dlistint_t.
 * @line_number: number of interpreted line
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *tmp = *head;

	if (!tmp || tmp->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free(lineptr);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp->next->n += tmp->n;
	_pop(head, line_number);
}



#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a stack
 * @head: pointer to the stack
 * @n: value of the new node
 * Return: pointer to the new node
 */
_stack_t *add_dnodeint_end(_stack_t **head, const int n)
{
	_stack_t *new = NULL, *current = NULL;

	new = malloc(sizeof(_stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(global.stack, global.file);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	new->prev = current;

	return (new);
}

/**
 * delete_dnodeint_at_end - deletes the last node of a stack
 * @head: pointer to the stack
 * Return: void
 */
void delete_dnodeint_at_end(_stack_t **head)
{
	_stack_t *current = NULL;

	if (*head == NULL)
		return;

	current = *head;
	while (current->next != NULL)
		current = current->next;

	if (current->prev != NULL)
		current->prev->next = NULL;
	else
		*head = NULL;

	free(current);
}

/**
 * add_dnodeint - adds a new node at the beginning of a stack
 * @head: pointer to the stack
 * @n: value of the new node
 * Return: pointer to the new node
 */
_stack_t *add_dnodeint(_stack_t **head, const int n)
{
	_stack_t *new = NULL;

	new = malloc(sizeof(_stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(global.stack, global.file);
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;
	new->next = *head;

	if (*head != NULL)
		(*head)->prev = new;

	*head = new;

	return (new);
}

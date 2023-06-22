#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _push(_stack_t **stack, unsigned int line_number)
{
	_stack_t *new_node = NULL;
	int number;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (is_number(global.line[1]) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(global.line[1]);

	new_node = malloc(sizeof(_stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * _pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _pall(_stack_t **stack, unsigned int line_number)
{
	_stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _pint(_stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * _pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _pop(_stack_t **stack, unsigned int line_number)
{
	_stack_t *current = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	if (current->next != NULL)
	{
		*stack = current->next;
		current->next->prev = NULL;
	}
	else
		*stack = NULL;

	free(current);
}

/**
 * _swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _swap(_stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

#include "monty.h"


/**
 * _mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _mod(_stack_t **stack, unsigned int line_number)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	mod = (*stack)->next->n % (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = mod;
}

/**
 * _pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _pchar(_stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _pstr(_stack_t **stack, unsigned int line_number)
{
	_stack_t *tmp = *stack;

	(void)line_number;

	while (tmp != NULL && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _rotl(_stack_t **stack, unsigned int line_number)
{
	int n;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	n = (*stack)->n;
	_pop(stack, line_number);
	add_dnodeint_end(stack, n);
}

/**
 * _rotr - rotates the stack to the bottom
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _rotr(_stack_t **stack, unsigned int line_number)
{
	_stack_t *tmp = *stack;
	int n;

	(void)line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	while (tmp->next != NULL)
		tmp = tmp->next;

	n = tmp->n;
	delete_dnodeint_at_end(stack);
	add_dnodeint(stack, n);
}

#include "monty.h"

/**
 * _nop - doesn’t do anything
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _nop(_stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _add(_stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = sum;
}

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _sub(_stack_t **stack, unsigned int line_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	sub = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = sub;
}

/**
 * _div - divides the second top element of the stack by the top element
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _div(_stack_t **stack, unsigned int line_number)
{
	int div;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	div = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n = div;
}

/**
 * _mul - multiplies the second top element of the stack with the top element
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _mul(_stack_t **stack, unsigned int line_number)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all(*stack, global.file);
		exit(EXIT_FAILURE);
	}

	mul = (*stack)->n * (*stack)->next->n;
	_pop(stack, line_number);
	(*stack)->n = mul;
}

#include"monty.h"

/**
 * adding_to_stack - Adds a node to the stack.
 * @new_one: Pointer to the new node.
 * @d: Interger representing the line number of of the opcode.
 */
void adding_to_stack(stack_t **new_one, __attribute__((unused))unsigned int d)
{
	stack_t *tmp;

	if (new_one == NULL || *new_one == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_one;
		return;
	}
	tmp = head;
	head = *new_one;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * printing_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void printing_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * popping - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void popping(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}


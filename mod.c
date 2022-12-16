#include "monty.h"
/**
 * f_mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @h: stack head
 * @count: line_number
 * Return: no return
*/
void f_mod(stack_t **h, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *h;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	h = *h;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*h = h->next;
	free(h);
}

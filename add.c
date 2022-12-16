#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @h: stack head
 * @count: line_number
 * Return: no return
*/
void f_add(stack_t **h, unsigned int count)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(bus.file);
		free(bus.content);
		free_stack(*h);
		exit(EXIT_FAILURE);
	}
	h = *h;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*h = h->next;
	free(h);
}

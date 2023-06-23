#include "monty.h"
/**
 * s_mod - computes the rest of the division
 * @head:  head pointer
 * @lineNum: line counter
 * Return: nothing
*/
void s_mod(stack_t **head, unsigned int lineNum)
{
	stack_t *temp;
	int l = 0, curr;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		l++;
	}
	if (l < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", lineNum);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	curr = temp->next->n % temp->n;
	temp->next->n = curr;
	*head = temp->next;
	free(temp);
}

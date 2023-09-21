#include "main.h"
/**
 * _chain - built linked list with directories
 * @a:fullpath
 * Return: head
 **/
shell_t *_chain(char *a)
{
	shell_t *head = NULL;
	char *tok;

	tok = _strtok(a, ":");
	while (tok != NULL)
	{
		head = _add_nodeint_end(&head, tok);
		tok = _strtok(NULL, ":");
	}
	return (head);
}
/**
 * _add_nodeint_end - add a new string to a node at the end
 * @head: head
 * @d: directory path
 * Return: head
 **/
shell_t *_add_nodeint_end(shell_t **head, char *d)
{
	shell_t *new_node;
	shell_t *last_node = *head;

	new_node = malloc(sizeof(shell_t));
	if (new_node == NULL)
		return (NULL);
	new_node->dic = d;
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new_node;
	}
	return (*head);
}
/**
 * free_list - frees a list_t list
 * @head: head of a node
 */
void free_list(shell_t *head)
{
	shell_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

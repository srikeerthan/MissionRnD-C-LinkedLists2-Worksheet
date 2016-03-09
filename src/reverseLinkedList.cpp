/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node * reverseLinkedList(struct node *head) {
	struct node *temp, *prev1 = NULL, *prev2 = NULL;
	if (head == NULL)
		return NULL;
	if(head->next == NULL)
		return head;
	else if (head->next->next == NULL)
	{
		temp = head;
		temp = temp->next;
		temp->next = head;
		head->next = NULL;
		return temp;
	}

	temp = head;
	while (temp != NULL)
	{
		if (temp == head)
			prev2 = temp;
		else if (temp == head->next)
			prev1 = temp;
		else if (prev2 == head)
		{
			prev2->next = NULL;
			prev1->next = prev2;
			prev2 = prev1;
			prev1 = temp;
		}
		else
		{
			prev1->next = prev2;
			prev2 = prev1;
			prev1 = temp;
		}
		temp = temp->next;
	}
	prev1->next = prev2;
	return prev1;
}

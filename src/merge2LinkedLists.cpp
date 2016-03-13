/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node  *temp1, *temp2, *temp3, *prev1, *prev2;
	temp2 = prev2 = head2;
	temp1 = prev1 = head1;
	if (temp1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;
	while (temp1 != NULL&&temp2 != NULL)
	{
		if (head2->num <= head1->num)
		{
			temp3 = head2->next;
			head2->next = head1;
			head1 = head2;
			head2 = temp3;
			temp2 = prev2 = head2;
			temp1 = prev1 = head1;
		}
		else if (head2->num <= temp1->num)
		{
			temp3 = head2->next;
			prev1->next = head2;
			head2->next = temp1;
			temp2 = prev2 = head2 = temp3;
			temp1 = prev1->next;
		}
		prev1 = temp1;
		if (temp1 != NULL)
			temp1 = temp1->next;
		else
			break;
	}
	if (temp2 != NULL)
		prev1->next = temp2;
	return head1;
}

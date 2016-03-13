/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<=0)
		return NULL;
	int count = 1;
	struct node *temp,*nwe;
	temp = head;
	while (temp != NULL)
	{
		if (K == count)
		{
			count = 1;
			nwe = (struct node *)malloc(sizeof(struct node));
			nwe->num = K;
			nwe->next = temp->next;
			temp->next = nwe;
			temp = temp->next->next;
		}
		else
		{
			temp = temp->next;
			count++;
		}
	}
	return head;
}

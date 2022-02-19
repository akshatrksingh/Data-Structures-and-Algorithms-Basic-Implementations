#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;

	node(int d)
	{
		data = d;
		next = NULL;
	}
};

void display(node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<"\n";
}

int length(node *head)
{
	int len = 0;
	while(head != NULL)
	{
		len++;
		head = head->next;
	}
	return len;
}

void insertAtBeg(node *&head, int d)
{
	if(head == NULL)
	{
		head = new node(d);
		return;
	}
	node *n = new node(d);
	n->next = head; // (*n).next = head;
	head = n; 
}

void insertAtEnd(node *&head, int d)
{
	if(head == NULL)
	{
		head = new node(d);
		return;
	}

	node *end = head;
	while(end->next != NULL)
	{
		end = end->next;
	}
	end->next = new node(d);
}

void deleteAtBeg(node *&head)
{
	if(head == NULL)
	{
		return;
	}
	node *tmp = head->next;
	delete head;
	head = tmp;
}

void deleteAtEnd(node *&head)
{
	if(head == NULL)
	{
		return;
	}
	node *tmp1 = head;   // last
	node *tmp2 = head;   // second last
	while(tmp1->next != NULL)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = NULL;
	delete tmp1;
}

void deleteAtKthPos(node *&head, int k)
{
	if(head == NULL || k > length(head))
	{
		return;
	}
	else if(k == 1)
	{
		deleteAtBeg(head);
		return;
	}
	node *tmp1 = head;   // kth
	node *tmp2 = head;   // (k-1)th
	while(--k)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2->next = tmp1->next;
	delete tmp1;
}

int main()
{
	node *head = NULL;
	insertAtBeg(head, 21);
	insertAtEnd(head, 53);
	insertAtEnd(head, 23);
	insertAtEnd(head, 433);
	insertAtEnd(head, 5);
	insertAtBeg(head, 241);
	insertAtEnd(head, 522);
	insertAtEnd(head, 344);
	insertAtEnd(head, 44);
	insertAtEnd(head, 1);
	display(head);
	deleteAtBeg(head);
	display(head);
	deleteAtEnd(head);
	display(head);
	deleteAtKthPos(head, 4);
	display(head);
	deleteAtKthPos(head, 1);
	display(head);
	deleteAtBeg(head);
	display(head);
	return 0;
}

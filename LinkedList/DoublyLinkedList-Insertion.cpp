#include <bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node *prev;
	node(int d)
	{
		data = d;
		prev = NULL;
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
	n->next = head;
	n->prev = NULL;
	head->prev = n;
	head = n; 
}

void insertAtEnd(node *&head, int d)
{
	if(head == NULL)
	{
		head = new node(d);
		return;
	}
	node *n = new node(d);
	node *end = head;
	while(end->next != NULL)
	{
		end = end->next;
	}
	n->prev = end;
	end->next = n;
}

void insertAtKthPos(node *&head, int d, int k)
{
	if(head == NULL || k <= 1)
	{
		insertAtBeg(head, d);
	}
	else if(k > length(head))
	{
		insertAtEnd(head, d);
	}
	else
	{
		int jmp = 1;
		node *tmp = head;
		while(jmp < k-1)
		{
			tmp = tmp->next;
			jmp++;
		}
		node *n = new node(d);
		n->next = tmp->next;
		n->prev = tmp;
		tmp->next = n; 
		n->next->prev = n;
	}
}

int main()
{
	node *head = NULL;
	insertAtBeg(head, 21);
	insertAtBeg(head, 73);
	insertAtBeg(head, 664);
	insertAtEnd(head, 45);
	insertAtEnd(head, 254);
	insertAtEnd(head, 988);
	insertAtEnd(head, 3);
	display(head);
	insertAtKthPos(head, 67, 4);
	display(head);
	insertAtKthPos(head, 2744, 1);
	display(head);
	cout<<length(head);
	return 0;
}

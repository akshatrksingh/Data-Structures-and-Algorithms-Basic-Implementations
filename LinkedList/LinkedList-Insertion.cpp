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
		tmp->next = n; 
	}
}


int main()
{
	node *head = NULL;
	insertAtBeg(head, 21);
	display(head);
	insertAtBeg(head, 231);
	display(head);
	insertAtKthPos(head, 5, 1);   // position numering starts from 1, not 0
	display(head);
	insertAtKthPos(head, 62, 2);
	display(head);
	insertAtBeg(head, 25);
	display(head);
	insertAtEnd(head, 3);
	display(head);
	insertAtKthPos(head, 5222, 3);
	display(head);
	insertAtKthPos(head, 223, 4);
	display(head);
	insertAtEnd(head, 53);
	display(head);
	return 0;
}

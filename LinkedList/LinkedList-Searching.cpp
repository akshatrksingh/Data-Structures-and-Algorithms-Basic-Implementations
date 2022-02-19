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

void search(node *head, int key)
{
	node *tmp = head;
	while(tmp != NULL)
	{
		if(tmp->data == key)
		{
			cout<<key<<" is found\n";
			return;
		}
		tmp = tmp->next;
	}
	cout<<key<<" is not found\n";
}

int main()
{
	node *head = NULL;
	insertAtBeg(head, 21);
	display(head);
	insertAtBeg(head, 231);
	display(head);
	insertAtKthPos(head, 5, 1);
	display(head);
	insertAtKthPos(head, 62, 2);
	display(head);
	insertAtKthPos(head, 5222, 3);
	display(head);
	insertAtKthPos(head, 223, 2);
	display(head);
	insertAtEnd(head, 53);
	display(head);
	search(head, 34);
	search(head, 231);
	search(head, 62);
	insertAtEnd(head, 453);
	display(head);
	search(head, 453);
	return 0;
}

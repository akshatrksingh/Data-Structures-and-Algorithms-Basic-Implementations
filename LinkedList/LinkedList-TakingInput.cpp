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

void insertAtKthNode(node *&head, int d, int k)
{
	if(head == NULL || k == 0)
	{
		insertAtBeg(head, d);
	}
	else if(k > length(head))
	{
		insertAtEnd(head, d);
	}
	else
	{
		int jump = 1;
		node *tmp = head;
		while(jump <= k-1)
		{
			tmp = tmp->next;
			jump++;
		}
		node *n = new node(d);
		n->next = tmp->next;
		tmp->next = n; 
	}
}

node *takeInput()
{
	node *head = NULL;
	int a, b;
	cout<<"Enter the number to indicate stop accepting inputs\n";
	cin>>a;
	cout<<"Enter the numbers in the linked list\n";
	cin>>b;
	do
	{
		insertAtEnd(head, b);
		cin>>b;
	}while(b != a);
	return head;
}

int main()
{
	node *head = takeInput();
	display(head);
	return 0;
}
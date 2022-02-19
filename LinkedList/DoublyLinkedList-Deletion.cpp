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

void displayReverse(node *head)
{
	node *tail = head;
	while(tail->next != NULL)
	{
		tail = tail->next;
	}
	while(tail != head)
	{
		cout<<tail->data<<" ";
		tail = tail->prev;
	}
	cout<<tail->data<<" ";
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

void deleteAtBeg(node *&head)
{
	if(head == NULL)
	{
		return;
	}
	node *tmp = head->next;
	if(head->next != NULL)
	{
		head->next->prev = head->prev;
	}
	delete head;
	head = tmp;
}

void deleteAtEnd(node *&head)
{
	if(head == NULL)
	{
		return;
	}
	node *tmp = head;   
	while(tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	delete tmp;
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
	else if(k == length(head))
	{
		deleteAtEnd(head);
		return;
	}
	node *tmp = head;   
	while(--k)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = tmp->next;
	tmp->next->prev = tmp->prev;
	delete tmp;
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
	displayReverse(head);
	deleteAtBeg(head);
	display(head);
	displayReverse(head);
	deleteAtEnd(head);
	display(head);
	displayReverse(head);
	deleteAtKthPos(head, 4);
	display(head);
	displayReverse(head);
	deleteAtKthPos(head, 1);
	display(head);
	displayReverse(head);
	deleteAtBeg(head);
	display(head);
	displayReverse(head);
	return 0;
}
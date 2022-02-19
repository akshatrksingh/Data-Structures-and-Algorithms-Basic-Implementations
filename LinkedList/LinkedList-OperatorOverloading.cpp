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

// void operator<<(ostream &os, node *head)
// {
// 	display(head);
// }

ostream& operator<<(ostream &os, node *head)
{
	display(head);
	return os;
}

istream& operator>>(istream &is, node *&head)
{
	head = takeInput();
	return is;
}

int main()
{
	node *head1;
	node *head2;
	cin>>head1>>head2;
	cout<<head1<<head2;
	return 0;
}

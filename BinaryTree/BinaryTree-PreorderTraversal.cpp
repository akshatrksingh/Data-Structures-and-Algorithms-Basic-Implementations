#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* buildTree()
{
	int d;
	cout<<"";
	cin>>d;

	if(d == -1)
	{
		return NULL;
	}
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void display(node *root)
{
	cout<<"";
	if(root == NULL)
	{
		return;
	}	

	cout<<root->data<<" ";
	display(root->left);
	display(root->right);
}

int main()
{
	node* root = buildTree();
	display(root);
	cout<<"end";
	return 0;
}

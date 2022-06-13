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

node* insert(node *root, int data)
{
	if(root == NULL)
	{
		return new node(data);
	}
	if(data <= root->data)
	{
		root->left = insert(root->left, data);	
	}
	else
	{
		root->right = insert(root->right, data);
	}
	return root; 
}

node* buildTree()
{
	int d;
	cout<<"";
	cin>>d;

	node* root = NULL;
	while(d != -1)
	{
		root = insert(root, d);
		cin>>d;
	}
	return root;

}

void display(node *root)
{
	cout<<"";
	if(root == NULL)
	{
		return;
	}	

	display(root->left);
	cout<<root->data<<" ";
	display(root->right);
}

int main()
{
	node* root = buildTree();
	display(root);
	return 0;
}
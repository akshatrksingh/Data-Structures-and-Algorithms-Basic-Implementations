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

node* del(node *root, int data)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(data < root->data)
	{
		root->left = del(root->left, data);
		return root;
	}
	else if(data == root->data)
	{
		//Leaf node
		if(root->left == NULL && root->right == NULL)
		{
			delete root;
			return NULL;
		}
		//Node with 1 child
		else if(root->left != NULL && root->right == NULL)
		{
			node *tmp = root->left;
			delete root;
			return tmp;
		}
		else if(root->left == NULL && root->right != NULL)
		{
			node *tmp = root->right;
			delete root;
			return tmp;
		}
		//Node with 2 children
		else
		{
			node *replace = root->right;
			//inorder successor from right subtree
			while(replace->left != NULL)
			{
				replace = replace->left;
			}
			root->data = replace->data;
			root->right = del(root->right, replace->data);
			return root;
		}
	}
	else
	{
		root->right = del(root->right, data);
		return root;
	}
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
	int n;
	cin>>n;
	root = del(root, n);
	display(root);
	return 0;
}
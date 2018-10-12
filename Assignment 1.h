/*Given binary tree with n nodes, perform following operations on it:
1. Perform preorder and post order traversal
2. Create a mirror image of it
3. Find the height of tree
4. Copy this tree to another [operator=]
5. Count number of leaves, number of internal nodes.
6. Erase all nodes in a binary tree.
(implement both recursive and non-recursive methods)*/

#include<iostream>

using namespace std;

class node
{
	node *left, *right;
	int data;
	public:
	node()
	{
		left=NULL;
		right=NULL;
		data=0;
	}
	friend class tree;
};

class tree
{
	node *root;
	public:
		tree()
		{
			root=NULL;
		}
		void insert();
		void show(node *);
		void display()
		{
			show(root);
		}
};

void tree::insert()
{
	node *current;
	node *new1;
	new1=new node;
	cout<<"Enter value"<<endl;
	cin>>new1->data;
	if(root==NULL)
		root=new1;
	else
	{
		char ch;
		bool flag;
		current=root;
		while(flag==false)
		{
			cout<<"Enter l to insert to the left, \n\tr to insert to the right"<<endl;
			cin>>ch;
			switch(ch)
			{
				case 'l':
					if(current->left==NULL)
					{
						current->left=new1;
						flag=true;
					}
					else
						current=current->left;
					break;
				case 'r':
					if(current->right=NULL)
					{
						current->right=new1;
						flag=true;
					}
					else
						current=current->right;
					break;
			}
		}
	}
}

void tree::show(node *new1)
{
	if(new1==NULL)
		return;
	cout<<new1->data<<endl;
	show(new1->left);
	show(new1->right);
}

int main()
{
	tree t;
	int ch;
	do
	{
		cout<<"Enter\n\t1. Insert Data\n\t2. Display Data\n\t3. Exit"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:
				t.insert();
				break;
			case 2:
				t.display();
			case 3:
				break;
			default:
				cout<<"Please enter valid value"<<endl;
		}
	}while(ch!=3);
	cout<<"Thank you for using the program!"<<endl;
	return 0;
}
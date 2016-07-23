#include <iostream>
using namespace std;

class BinarySearchTree
{
	struct node{
		int data;
		node* leftChild;
		node* rightChild;
		node* parent;
		
		node()
		{
			// all pointers to null
		}
		
		node(int data)
		{
			this->data = data;
			// all pointers to null
		}
	};
	
	node* root;
	
	public:
	
	BinarySearchTree()
	{
		root = NULL;
	}
	
	~BinarySearchTree()
	{
		// Todo
	}
	
	void insert(int data)
	{
		node* newNode = new node(data);
		if(root==NULL)
		{
			root = newNode;
		}
		else
		{
			node* sr == root;
			while(1)
			{
				if(sr->data > data && sr->leftChild!=NULL)
				{
					sr =sr->lc;
				}
				else if(sr->data < data && sr->rightChild!=NULL)
				{
					sr = sr->rc;
				}
				else
				{
					break;
				}
			}
			
		}
	}
};

// Main
int main()
{
	return 0;
}


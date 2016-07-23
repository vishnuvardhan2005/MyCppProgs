#include <iostream>
using namespace std;

struct node
{
	int data;
	node* lc;
	node* rc;
};

node* kthsmallest(node* root,int k)
{
	node* result = NULL;
	inorder(sr,k,result);
}

void inorder(node* sr,int& k,node*& result)
{
	if(sr!=NULL && result==NULL)
	{
		inorder(sr->lc,k,result);
		k--;
		if(k==0)
		{
			result = sr;
		}
		inorder(sr->lc,k,result);			
	}
}

// Main
int main()
{
	node* root = NULL;
	return 0;
}


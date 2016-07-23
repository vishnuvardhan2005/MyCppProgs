#include <iostream>

void swap(int& a,int& b)
{
	int t = a;
	a = b;
	b = t;
}

void heapify(int* a,int n,int i)
{
	int left = 2*i;
	int right = 2*i+1;
	int maxIndex = i;
	if(left<=n && a[i]<a[left])
		maxIndex = left;
	if(right<=n && a[right]>a[maxIndex])
		maxIndex = right;
	if(maxIndex!=i)
	{
		swap(a[i],a[maxIndex]);
		heapify(a,n,maxIndex);
	}
}

void heap_insert(int* a,int n,int v)
{
	n = n+1;
	a[n] = v;
	int i=n;
	int parent = i/2;
	while(i>0 && a[parent]<a[i])
	{
		swap(a[i],a[parent]);
		i = parent;
		parent = i/2;
	}
}

int getIndex(int* a,int n,int v)
{
	int result = -1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==v)
		{
			result = i;
		}
	}
	return result;
}

void heap_remove(int* a,int n,int v)
{
	int index = getIndex(a,n,v);
	if(index>=1 && index<=n)
	{
		a[index]=a[n];
		n--;
		heapify(a,n,index);
	}
}

// Main
int main()
{
	int a[1000];
	int n=0;
	heap_insert(a,n,10);
	return 0;
}

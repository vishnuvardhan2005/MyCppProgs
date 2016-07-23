#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void swap(long long& a,long long& b)
{
	long long t = a;
	a = b;
	b = t;
}

void heapify(long long* a,long long n,long long i)
{
	long long left = 2*i;
	long long right = 2*i+1;
	long long minIndex = i;
	if(left<=n && a[i] > a[left])
		minIndex = left;
	if(right<=n && a[right] < a[minIndex])
		minIndex = right;
	if(minIndex!=i)
	{
		swap(a[i],a[minIndex]);
		heapify(a,n,minIndex);
	}
}

void heap_insert(long long* a,long long& n,long long v)
{
	n = n+1;
	a[n] = v;
	long long i=n;
	long long parent = i/2;
	while(parent>0 && a[parent]>a[i])
	{
		swap(a[i],a[parent]);
		i = parent;
		parent = i/2;
	}
}

long long getIndex(long long* a,long long n,long long v)
{
	long long result = -1;
	for(long long i=1;i<=n;i++)
	{
		if(a[i]==v)
		{
			result = i;
		}
	}
	return result;
}

void heap_remove(long long* a,long long& n,long long v)
{
	long long index = getIndex(a,n,v);
	if(index>=1 && index<=n)
	{
		a[index]=a[n];
		n--;
		heapify(a,n,index);
	}
}

long long heapMinimum(long long* a,long long n)
{
	return a[1];
}

// Main
int main()
{
	long long a[100000];
	long long q;
	long long n=0;
	cin >> q;
	long long choice;
	long long v;
	while(q--)
	{
		cin >> choice;
		switch(choice)
		{
			case 1:
				cin >> v;
				heap_insert(a,n,v);
				break;
			case 2:
				cin >> v;
				heap_remove(a,n,v);
				break;
			case 3:
				cout << heapMinimum(a,n) << endl;
				break;
			default:
				break;
		}
		
	}
	return 0;
}



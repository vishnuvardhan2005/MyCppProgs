#include <iostream>
using namespace std;

void printArray(int* a,int n)
{
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}

int getJustSmallerIndex(int* a,int n,int x)
{
	int low,high,mid;
	low = 0;
	high = n-1;
	while(low<=high)
	{
		mid = (low+high)/2;
		if(a[mid]==x)
			break;
		else if(a[mid]>x)
		{
			high = mid-1;
		}
		else
		{
			low = low+1;
		}
	}
	return mid;
}

int insert(int* a,int n,int x)
{
	// insert x in a
	int index = getJustSmallerIndex(a,n,x);
	for(int i=n+1;i>index;i--)
	{
		a[i]=a[i-1];
	}
	a[index+1]=x;
}

int main()
{
	int *a = new int[10];
	for(int i=0;i<9;i++)
	{
		a[i]=i+1;
	}
	
	printArray(a,9);
	insert(a,9,0);
	printArray(a,10);
	return 0;
}d

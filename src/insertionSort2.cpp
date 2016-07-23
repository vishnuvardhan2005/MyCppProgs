#include <iostream>
using namespace std;

#define SIZE 100

void printArray(int* a,int n)
{
	for(int i=0;i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}

void insertionSort(int* a,int n)
{
	if(n>1)
	{
		insertionSort(a,n-1);
		int low,high,mid,key;
		key = a[n-1];
		low =0;
		high = n-2;
		while(low<=high)
		{
			mid = (low+high)/2;
			if(a[mid]==key)
			{
				break;
			}
			else if(a[mid]>key)
			{
				high = high-1;
			}
			else
			{
				low = low+1;
			}
		}
		
		for(int i=n-1;i>=mid;i++)
		{
			a[i+1]=a[i];
		}
		a[mid]=key;
	}
}

int main()
{
	int n;
	cin >> n;
	int* a=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	//int a[]={3,1,2,69,4,12,43,66,87,23,45,11};
	//int n = sizeof(a)/sizeof(n);
	
	printArray(a,n);
	insertionSort(a,n);
	printArray(a,n);
	return 0;
}

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
		int key,j;
		insertionSort(a,n-1);
		key = a[n-1];
		j = n-2;
		while(j>=0 && a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=
		key;
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

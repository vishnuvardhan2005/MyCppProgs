#include <iostream>
using namespace std;

int maxSubArray_NonContinous(int* a,int n)
{
	int maxSum = 0;
	int max = a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
			maxSum = maxSum+a[i];
		if(a[i]>max)
			max = a[i];
	}
	return maxSum==0 ? max : maxSum;
}

int max(int a,int b)
{
	return a>b?a:b;
}

int maxSubArray_Continous(int* a,int n)
{
	int max_so_far = 0;
	int max_ending_here = 0;
	int iMax = a[0];
	for(int i=0;i<n;i++)
	{
		max_ending_here = max(0,max_ending_here+a[i]);
		max_so_far = max(max_so_far,max_ending_here);
		if(a[i]>iMax) iMax=a[i];
	}
	return max_so_far==0 ? iMax :max_so_far; 
}

// Main
int main()
{
	int testCases;
	int n;
	int* a;
	cin >> testCases;
	while(testCases--)
	{
		cin >> n;
		a = new int[n];
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		cout << maxSubArray_Continous(a,n) << " " << maxSubArray_NonContinous(a,n)<< endl;
		delete[] a;
	}
	return 0;
}


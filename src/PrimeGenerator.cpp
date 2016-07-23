#include <iostream>
using namespace std;

/*bool isPrime(int num)
{
	if(num <=1)
	{
		return false;
	}
	else
	{
		for(int i=2;i<=num/2;i++)
		{
			if(num%i==0)
				return false;
		}
	}
	return true;
}*/

// 
void PrimeGenerator(int* arr,int n)
{
	if(n==0)
		return;
		
	for(int i=0;i<n;i++)
	{
		if(i==0 || i==1){
			arr[i] = false; // 0 is not prime
		}else{
			arr[i]=true;
		}
	}	
	// n > 2. 	
}

int main()
{
	int t;
	int m,n;
	int* arr;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> m;
		cin >> n;
		
		// Generate prime numbers between
		cout << endl;
	}
	return 0;
}

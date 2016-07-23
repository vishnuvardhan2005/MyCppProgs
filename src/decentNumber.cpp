#include <iostream>
using namespace std;

void printAll(char* s,int k,int m)
{
	if(k>m)
		cout << s << endl;
	else
	{
		s[k] = '3';
		printAll(s,k+1,m);
		s[k] = '5';
		printAll(s,k+1,m);
	}
}

void printAllNumbers(char* s,int k,int m)
{
	//for(int i=m;i>=k;i--)
	//{
//	int i = 0;
//		printAll(s+i,i,m);
int		i = 1;
		printAll(s+i,i,m);
		//cout << s+i << endl;		
	//}
}

// Main
int main()
{
	char s[] = "555";
	printAllNumbers(s,0,2);
	return 0;
}

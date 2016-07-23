#include <iostream>
using namespace std;

void permutations(char* s,int k,int m)
{
	if(k==m)
		cout << s << endl;
	else
	{
		for(int i=k;i<=m;i++)
		{
			swap(s[i],s[k]);
			permutations(s,k+1,m);
			swap(s[i],s[k]);	
		}
	}
}

// Main
int main()
{
	char s[]="112";
	permutations(s,0,2);
	return 0;
}


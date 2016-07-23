#include <iostream>
using namespace std;

void subSetGenerator(char* s,int k,int m)
{
	if(k>m)
		cout << s << endl;
	else
	{
		s[k] = '0';
		subSetGenerator(s,k+1,m);
		s[k] = '1';
		subSetGenerator(s,k+1,m);		
	}
}

// Main
int main()
{
	char s[]="0000";
	subSetGenerator(s,0,3);
	return 0;
}


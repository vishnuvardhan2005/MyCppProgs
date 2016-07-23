#include <iostream>
using namespace std;

int message(int a)
{
	cout << "hello" << a << endl;
	return 1;	
}

// Main
int main()
{
	int a = message(message(1));
	cout << a << endl;
	return 0;
}


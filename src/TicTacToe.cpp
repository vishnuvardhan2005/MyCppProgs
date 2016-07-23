#include <iostream>
using namespace std;

class TicTacToe
{
	int a[3][3];
	int n;
	
	public:
	
	TicTacToe()
	{
		n = 3;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				a[i][j]=0;	
			}
		}	
	}
	
	void displayBoard()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				
			}
		}		
	}
};

// Main
int main()
{ 
	TicTacToe ticTacToe;
	ticTacToe.displayBoard();
	return 0;
}


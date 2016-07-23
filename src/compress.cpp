#include <iostream>
#include <string.h>
using namespace std;

#define MAX_SIZE 1000

char buf[MAX_SIZE];
int startByte = 0;
int startBit = 0;

void compress(char* s)
{
	// This populates buf with compressed string
	// s is assumed to have only a-z
	char temp;
	char temp1;
	int bitsLeft = 0;
	for(int i=0;s[i]!='\0';i++)
	{
		temp = s[i]-'0'+1;
		if(startBit<=3)
		{
			// enough size
			temp = temp << (3-startBit);
			buf[startByte] = buf[startByte] | temp;
			startBit = startBit + 5;
			if(startBit >=8)
			{
				startByte = startByte+1;
				startBit = startBit%8;
			}
		}
		else
		{
			// size is not enough
			temp1 = temp;
			temp1 = temp1 >> (startBit-3);
			buf[startByte] = buf[startByte] | temp1;
			bitsLeft = startBit - 3;
			
			startByte++;
			startBit = 0;
			// now fill rest of startBit-3 bits
			temp = temp << (8-bitsLeft);
			buf[startByte] = buf[startByte] | temp;
			startBit = bitsLeft;
		}
	}
	//buf[++startByte] = '\0';
}

void uncompress()
{
	
}

// Main
int main()
{
	memset(buf,'\0',MAX_SIZE);
	compress("abcdefdbjdsdksnfkfdsfsfdsfnsdfdfjdhdsufhsfejrebjfnererjrrrrbjbdjf");
	cout << buf << endl;
	cout << startByte << endl;
	return 0;
}


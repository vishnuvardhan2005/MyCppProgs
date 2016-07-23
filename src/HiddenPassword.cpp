#include <iostream>
#include <string.h>
using namespace std;

void printBinary(char c)
{
	char str[8];
	for(int i=7;i>=0;i--)
	{
		str[i] = ((c & 0x01) == 0) ? '0' : '1';
		c = c >> 1;
	}
	str[8]='\0';
	cout << str << endl;
}

char testBit(char c,int p)
{
	char mask = 0x01;
	while(--p)
	{
		mask = (mask << 1);
	}
	return ((c & mask)!=0x00) ? 0x01:0x00;
}

void decode(char* str1,char* str2)
{
	if(strlen(str1)!=6)
		throw "invalid params";
		
	char result1 = 0x00;
	char result2 = 0x00;
	char mask1 = 0x01;
	char mask2 = 0x08;
	for(int i=0;i<strlen(str1);i++)
	{
		result1 = result1 | (str1[i] & mask1);
		mask1 = mask1 << 1;
		
		result2 = result2 | (str1[(i+3)%6] & mask2);
		printBinary(mask2);
		mask2 = mask2 << 1;
		if(mask2 >= 0x32)
		{
			mask2 = 0x01;
		}
	}
	printBinary(result1);
	cout << (int)result1 << endl;
	printBinary(result2);
	cout << (int)result2 << endl;	
}

void decode1(char* str1,char* str2,int n)
{
	char temp[7];
	while(n--)
	{
		for(int i=0;i<6;i++)
		{
			temp[i]=str1[i+n*6];
		}
		char result = 0x00;
		for(int i=5;i>=0;i--)
		{
			result = result << 1;
			result = result | testBit(temp[i],i+1);
		}
		cout << temp[(int)result];
		
		result = 0x00;
		for(int i=5;i>=0;i--)
		{
			result = result << 1;
			result = result | testBit(temp[i],((i+3)%6)+1);
		}
		cout << temp[(int)result];
	}	
	
}


int main()
{
	char str1[]="qwe345 rf3Arg";
	char str2[]="XSBSRasdew9873465hkldsfsalndfvnfq489uqovkLKJHaeDaae555Sk5asdpASD";
    decode1(str1,str2,2);
	
	return 0;
}

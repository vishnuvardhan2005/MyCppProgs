#include <iostream>
#include <string.h>
using namespace std;

class BytesBuffer
{
	char buf[MAX_SIZE];
	int bits;
	public:
	ButesBuffer()
	{
		memset(buf,'\0',MAX_SIZE);
		bits = 0;
	}
	
	void pushBits(char c,int startPos,int n)
	{
		// pushes n bits from c to buf
		int insertBytePos = (bits+1)/8;
		// todo
	}
	
	char popBits(int n)
	{
		// pops first n bits from buf. first n bits if return value. n<=8
		
	}
};

// Main
int main()
{
	return 0;
}


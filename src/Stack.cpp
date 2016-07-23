#include <iostream>
using namespace std;

class Stack
{
	int *arr;
	int top;
	int n;
	
	public:
	
	Stack()
	{
		n = 10;
		top = -1;
		arr = new int[n];
	}
	
	~Stack()
	{
		delete[] arr;
	}
	
	bool IsEmpty()
	{
		return top==-1;
	}
	
	void push(int data)
	{
		if(top==n)
		{
			throw "Stack overflow";
		}
		else
		{
			arr[++top] = data;
		}
	}
	
	int pop()
	{
		if(this->IsEmpty())
		{
			throw "Stack underflow";
		}
		else
		{
			return arr[top--];			
		}
	}
};

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	
	cout << s.pop() << endl;
	
	s.push(50);
	
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	return 0;
}

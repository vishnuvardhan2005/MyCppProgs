#include <iostream>
using namespace std;

class Queue
{
	int* arr;
	int head;
	int tail;
	int n;
	
	public:
	
	Queue()
	{
		n = 10;
		arr = new int[10];
		head = tail = 0;
	}
	
	bool IsEmpty()
	{
		return head==tail;
	}
	
	void enqueue(int data)
	{
		int tailNext = (tail+1)%n;
		if(tailNext==head)
		{
			throw "Queue full";
		}
		else
		{
			arr[tail]=data;
			tail = tailNext;
		}
	}
	
	int dequeue()
	{
		if(tail==head)
		{
			throw "Queue empty";
		}
		else
		{
			int data = arr[head];
			head = (head+1)%n;
			return data;
		}
	}
};

// Main
int main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	cout << q.dequeue() << endl;
	q.enqueue(12);
	q.enqueue(221);
	while(!q.IsEmpty())
	{
		cout << q.dequeue() << endl;
	}
	return 0;
}

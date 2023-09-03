#include <iostream>
using namespace std;

class queue
{
private:
	int* arr;
	int size;
	unsigned cap;
	int head;
	int tail;
public:
	queue(int capacity) 
	{
		cap = capacity;
		tail = -1;
		size = head = 0;
		arr = new int[cap];
	}

	~queue()
	{
		delete[] arr;
	}

	int getSize()
	{
		return (size);
	}

	bool isFull()
	{
		return (size == cap);
	}

	void enqueue(int value)
	{
		if (isFull())
		{
			return;
		}

		tail++;
		arr[tail] = value;
		size++;
	}

	int front()
	{
		if (isEmpty())
		{
			return -1;
		}

		return arr[head];
	}

	int dequeue()
	{
		if (isEmpty())
		{
			return -1;
		}

		if (head == cap)
		{
			return -1;
		}

		int ans = arr[head];
		head++;
		size--;
		return ans;
	}

	bool isEmpty()
	{
		return	!(size);
	}
};

int main()
{
	queue var(3);
	var.enqueue(10);
	var.enqueue(20);
	var.enqueue(30);
	var.enqueue(40);
	cout << var.dequeue() << endl;
	cout << var.front() << endl;
	cout << var.getSize() << endl;
	cout << boolalpha << var.isEmpty() << endl;
	cout << boolalpha << var.isFull() << endl;
}

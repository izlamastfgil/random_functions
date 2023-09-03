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

		tail = (tail + 1) % cap; // circular property of queue.
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

		

		int ans = arr[head];
		head = (head + 1) % cap;
		size--;
		return ans;
	}

	bool isEmpty()
	{
		return	!(size);
	}
};


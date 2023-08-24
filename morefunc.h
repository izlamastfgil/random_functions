#ifndef MOREFUNC_H
#define MOREFUNC_H

class stack
{
private:
	int* arr = new int [1] {};
	int size;
	int index;
public:
	stack() : index(0), size(1) {}

	void push(int value)
	{
		if (index == size)
		{
			int* newArr = new int[size * 2];
			for (size_t i = 0; i < size; i++)
			{
				newArr[i] = arr[i];
			}
			delete[] arr;
			arr = newArr;
			size *= 2;
		}

		arr[index] = value;
		index++;
	}
	int pop()
	{
		if (index == 0)
		{
			return -1;
		}

		index--;
		return arr[index];
		
	}
	bool isEmpty()
	{
		return ((index == 0) ? true : false);
	}
	int sizeOfStack()
	{
		return (index);
	}
};

#endif // !"MOREFUNC_H"

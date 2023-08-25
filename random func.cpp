#include <iostream>
using namespace std;
#include "morefunc.h"

stack stackInput(stack var)
{
	int value;
	cin >> value;

	while (value != -1)
	{
		var.push(value);
		cin >> value;
	}
	return var;
}

void empty(stack &var, int varSize)
{
	if (varSize == 0)
	{
		return;
	}
	var.pop();
	empty(var, varSize - 1);
}

int main()
{
	stack var;
	var = stackInput(var);
	cout << "Size: " << var.sizeOfStack() << endl;
	cout << "Popped Element: " << var.pop() << endl;
	cout << "Size: " << var.sizeOfStack() << endl;
	cout << "Is Stack Empty? : " << ((var.isEmpty()) ? "YES" : "NO") << endl;
	cout << "Emptying Entire file" <<  endl;
	empty(var, var.sizeOfStack());
	cout << "Is Stack Empty? : " << ((var.isEmpty()) ? "YES" : "NO") << endl;
	return 0;
}

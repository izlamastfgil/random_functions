#include <iostream>
using namespace std;
#include "morefunc.h"

void stackInput(stack &var)
{
	int value;
	cin >> value;

	while (value != -1)
	{
		var.push(value);
		cin >> value;
	}

}

int main()
{
	stack var;
	stackInput(var);
	cout << "Size: " << var.sizeOfStack() << endl;
	cout << "Popped Element: " << var.pop() << endl;
	cout << "Size: " << var.sizeOfStack() << endl;
	cout << "Is Stack Empty? : " << ((var.isEmpty()) ? "YES" : "NO") << endl;
	return 0;
}

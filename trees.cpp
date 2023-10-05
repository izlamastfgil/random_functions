#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include "treeSource.h"

//class tree
//{
//public:
//	int value;
//	vector<tree*> nodes;
//
//	tree(int val) : value(val) {}
//
//};
//
//tree* input()
//{
//	int val;
//	cout << "Enter Value: ";
//	cin >> val;
//	tree* newLeaf = new tree(val);
//
//	int nodes;
//	cout << "Enter number of Children: ";
//	cin >> nodes;
//	cout << endl;
//
//	for (size_t i = 0; i < nodes; i++)
//	{
//		tree* child = input();
//		newLeaf->nodes.push_back(child);
//	}
//
//	return newLeaf;
//}
//
//tree* inputLine()
//{
//	int rootVal;
//	cout << "Enter Root value: ";
//	cin >> rootVal;
//
//	tree* newNode = new tree(rootVal);
//
//	/*int numChild;
//	cin >> numChild;*/
//
//	queue<tree*> popper;
//	popper.push(newNode);
//
//	while (popper.size() != 0)
//	{
//		tree* front = popper.front();
//		popper.pop();
//
//		cout << "Enter Number of Children of " << front->value << " : ";
//		int numChild;
//		cin >> numChild;
//
//		for (size_t i = 0; i < numChild; i++)
//		{
//			int childData;
//			cout << "Enter value of " << i << "th child of " << front->value << ": ";
//			cin >> childData;
//			
//			tree* newChild = new tree(childData);
//			front->nodes.push_back(newChild);
//			popper.push(newChild);
//		}
//	}
//
//	return newNode;
//
//
//}





int main()
{
	//tree* ans = input();

	//10 2 20 30 2 40 50 2 60 70 0 0 0 0

	tree var, arr;
	var.queueInput();
	var.linePrint();





	/*tree* arr = new tree(10);
	tree* child1 = new tree(20);
	tree* child2 = new tree(30);

	tree* grandchild1 = new tree(40);
	tree* grandchild2 = new tree(50);
	tree* grandchild3 = new tree(60);

	tree* greatgrandchild1 = new tree(70);
	tree* greatgrandchild2 = new tree(80);
	tree* greatgrandchild3 = new tree(90);
	tree* greatgrandchild4 = new tree(100);
	tree* greatgrandchild5 = new tree(110);

	arr->nodes.push_back(child1);
	arr->nodes.push_back(child2);

	child1->nodes.push_back(grandchild1);
	child1->nodes.push_back(grandchild2);
	child2->nodes.push_back(grandchild3);

	grandchild2->nodes.push_back(greatgrandchild3);
	grandchild2->nodes.push_back(greatgrandchild4);
	grandchild3->nodes.push_back(greatgrandchild1);
	grandchild3->nodes.push_back(greatgrandchild2);
	greatgrandchild4->nodes.push_back(greatgrandchild5);*/

	//printTree(ans);
}
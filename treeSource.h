#include <iostream>
using namespace std;
#ifndef TREESOURCE_H
#define TREESOURCE_H
#include <vector>
#include <queue>

class treeNode
{
private:
	void change(treeNode* root, int initialDepth)
	{
		root->value = initialDepth++;
		for (size_t i = 0; i < root->child.size(); i++)
		{
			change(root->child[i], initialDepth);
		}
	}
public:
	int value;
	vector<treeNode*> child;

	treeNode() = default;

	~treeNode()
	{
		for (size_t i = 0; i < this->child.size(); i++)
		{
			delete this->child[i];
		}
	}

	inline void changeValueOfNodeWithDepth()
	{
		change(this, 0);
	}

	void input()
	{
		//int rootValue;
		//int level = 0;
		cout << "Enter root value: ";
		cin >> value;
		//treeNode* root = new treeNode(rootValue);

		int NoOfchild;
		cout << "Enter Number of children: ";
		cin >> NoOfchild;

		for (size_t i = 0; i < NoOfchild; i++)
		{
			treeNode* newChild = new treeNode();
			newChild->input();
			child.push_back(newChild);

			/*treeNode* newChild = input();
			newChild->child.push_back(newChild);*/
		}

		//return this;
	}

	void inputQueueLine()
	{
		cout << "Enter Root Value: ";
		cin >> value;

		queue<treeNode*> popper;
		popper.push(this);

		while (popper.size() != 0)
		{
			treeNode* free = popper.front();
			popper.pop();

			int numOfChild;
			cout << "Enter Number of Children of " << free->value << " : ";
			cin >> numOfChild;

			for (size_t i = 0; i < numOfChild; i++)
			{
				int childData;
				cout << "Enter value of " << i + 1 << " child of " << free->value << " : ";
				treeNode* newChild = new treeNode();
				cin >> newChild->value;

				free->child.push_back(newChild);
				popper.push(newChild);
			}
		}
	}

	int countNodes()
	{
		int sum = 0;

		for (size_t i = 0; i < this->child.size(); i++)
		{
			sum += this->child[i]->countNodes();
		}

		return sum + 1;
	}

	bool isSame(treeNode* root)
	{
		if (this == nullptr && root == nullptr)
			return true;
		if ((root == nullptr && this != nullptr) || (root != nullptr && this == nullptr))
			return false;
		if ((root->value != this->value) || (this->child.size() != root->child.size()))
			return false;

		bool flag = true;

		for (size_t i = 0; (i < this->child.size() && i < root->child.size()); i++)
		{
			flag = this->child[i]->isSame(root->child[i]);
			if (flag == false)
				return false;
		}

		return flag;
	}

	void printLineWise()
	{
		queue<treeNode*> ord;
		ord.push(this);

		while (ord.size() != 0)
		{
			treeNode* fre = ord.front();
			ord.pop();

			cout << fre->value << " : ";

			for (size_t j = 0; j < fre->child.size(); j++)
			{
				cout << fre->child[j]->value;
				ord.push(fre->child[j]);
				if (j == fre->child.size() - 1)
					break;
				cout << ", ";
			}
			cout << "\n";
		}
	}

	void inputLine(vector<treeNode*>& nexlevelvector)
	{
		//int rootValue;
		//int level = 0;
		cout << "Enter root value: ";
		cin >> value;
		//treeNode* root = new treeNode(rootValue);

		int NoOfchild;
		cout << "Enter Number of children: ";
		cin >> NoOfchild;

		for (size_t i = 0; i < NoOfchild; i++)
		{
			treeNode* newChild = new treeNode();
			child.push_back(newChild);
			nexlevelvector.push_back(newChild);

			/*treeNode* newChild = input();
			newChild->child.push_back(newChild);*/
		}
	}

	void print()
	{
		cout << this->value << " : ";
		for (size_t i = 0; i < this->child.size(); i++)
		{
			cout << this->child[i]->value;
			if (i == this->child.size() - 1)
				break;
			cout << ", ";
		}
		cout << endl;

		for (size_t i = 0; i < this->child.size(); i++)
		{
			this->child[i]->print();
		}
	}

	int sumNode()
	{
		int sum = 0;
		for (size_t i = 0; i < this->child.size(); i++)
		{
			sum += this->child[i]->sumNode();
		}
		return (sum + this->value);
	}

	treeNode* largestNum()
	{
		if (this == nullptr)
			return nullptr;

		treeNode* maxNode = this;
		for (size_t i = 0; i < this->child.size(); i++)
		{
			treeNode* temp = this->child[i]->largestNum();

			if (temp != nullptr && temp->value > this->value)
				maxNode = temp;
		}

		return maxNode;
	}

	int heightOfTree()
	{
		int height{};

		for (size_t i = 0; i < this->child.size(); i++)
		{
			int temp = this->child[i]->heightOfTree();

			height = max(height, temp);
		}

		return height + 1;
	}

	void depthElement(int dep)
	{
		if (dep == 0)
		{
			cout << this->value << " ";
			return;
		}

		for (size_t i = 0; i < this->child.size(); i++)
		{
			this->child[i]->depthElement(dep - 1);
		}
	}

	int leaf()
	{
		if (this->child.size() == 0)
			return 1;

		int leafNode{};
		for (size_t i = 0; i < this->child.size(); i++)
		{
			leafNode += this->child[i]->leaf();
		}

		return leafNode;
	}

	void preorder()
	{
		cout << this->value << " ";
		for (size_t i = 0; i < this->child.size(); i++)
		{
			this->child[i]->preorder();
		}
	}

	void postorder()
	{
		for (size_t i = 0; i < this->child.size(); i++)
		{
			this->child[i]->postorder();
		}

		cout << this->value << " ";
	}
};

class tree
{
public:
	int levels;
	treeNode* root;
	vector<treeNode*> CurrentLevelNodes;
	vector<treeNode*> NextLevelNodes;

	tree() : levels(0), root(new treeNode())
	{
		CurrentLevelNodes.push_back(root);
	}

	~tree()
	{
		delete root;
	}

	void create()
	{
		root->input();
	}
	void createLineway()
	{
		for (int i = 0; i < CurrentLevelNodes.size(); i++)
		{
			CurrentLevelNodes[i]->inputLine(NextLevelNodes);
		}
		CurrentLevelNodes.clear();

		//if there is entry in nextleve..then call createLineway
		if (NextLevelNodes.size() != 0)
		{
			CurrentLevelNodes = NextLevelNodes;
			NextLevelNodes.clear();
			createLineway();
		}
	}

	void linePrint()
	{
		root->printLineWise();
	}

	void queueInput()
	{
		root->inputQueueLine();
	}

	void print()
	{
		root->print();
	}

	int sumOfAllNodes()
	{
		return root->sumNode();
	}

	int NumberOfNodes()
	{
		return root->countNodes();
	}

	treeNode* greatest()
	{
		return root->largestNum();
	}

	int height()
	{
		return root->heightOfTree();
	}

	void depth(int dep)
	{
		root->depthElement(dep);
	}

	int numberOfLeafNodes()
	{
		return root->leaf();
	}

	void preorder()
	{
		root->preorder();
	}

	void postorder()
	{
		root->postorder();
	}

	void changeValueOfNodeWithDepth()
	{
		root->changeValueOfNodeWithDepth();
	}

	bool areTwoTreeSame(tree var)
	{
		return this->root->isSame(var.root);
	}
};

#endif // !TREESOURCE_H

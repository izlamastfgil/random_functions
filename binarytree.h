#include <queue>
#include <vector>
#ifndef BINARYTREE_H
#define BINARYTREE_H

class binaryTreeNode
{
private:
	int data;
	binaryTreeNode* left;
	binaryTreeNode* right;

public:

	binaryTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
	binaryTreeNode() : data(-1), left(nullptr), right(nullptr) {}

	~binaryTreeNode()
	{
		delete left;
		delete right;
	}

	void btPrint()
	{
		if (this == nullptr)
			return;

		cout << this->data << " : ";
		if (this->left != nullptr)
			cout << "L[" << this->left->data << "]";
		if (this->right != nullptr)
			cout << ", R[" << this->right->data << "]";
		cout << endl;

		if (this->left != nullptr)
			this->left->btPrint();

		if (this->right != nullptr)
			this->right->btPrint();
	}

	void printLevelWise()
	{
		queue<binaryTreeNode*> ans;
		ans.push(this);

		while (ans.size() != 0)
		{
			cout << ans.front()->data << " : ";

			if (ans.front()->left != nullptr)
			{
				cout << " L[" << ans.front()->left->data << "] ";
				ans.push(ans.front()->left);
			}

			if (ans.front()->right != nullptr)
			{
				cout << "R[" << ans.front()->right->data << "]";
				ans.push(ans.front()->right);
			}
			cout << endl;

			ans.pop();
		}
	}

	binaryTreeNode* Input()
	{
		int rootData;
		cout << "Enter Data: ";
		cin >> rootData;

		if (rootData == -1)
			return nullptr;

		binaryTreeNode* root = new binaryTreeNode(rootData);

		root->left = Input();
		root->right = Input();

		return root;
	}

	binaryTreeNode* lineWiseInput()
	{
		int rootData;
		printf("Enter Root Data: ");
		cin >> rootData;

		queue<binaryTreeNode*> popper;
		binaryTreeNode* root = new binaryTreeNode(rootData);
		popper.push(root);

		while (popper.size() != 0)
		{
			binaryTreeNode* foo = popper.front();
			popper.pop();

			int leftData, rightData;
			cout << "Enter Left Data and Right Data of " << foo->data << " : ";
			cin >> leftData >> rightData;

			if (leftData != -1)
			{
				binaryTreeNode* leftNode1 = new binaryTreeNode(leftData);
				foo->left = leftNode1;
				popper.push(foo->left);
			}

			if (rightData != -1)
			{
				binaryTreeNode* rightNode1 = new binaryTreeNode(rightData);
				foo->right = rightNode1;
				popper.push(foo->right);
			}
		}

		return root;
	}

	int numberOfNodes()
	{
		if (this == nullptr)
			return 0;

		return 1 + this->left->numberOfNodes() + this->right->numberOfNodes();
	}

	void postOrder()
	{
		if (this == nullptr)
			return;

		this->left->postOrder();
		this->right->postOrder();

		cout << this->data << " ";
	}

	void inOrder()
	{
		if (this == nullptr)
			return;

		this->left->inOrder();
		cout << this->data << " ";
		this->right->inOrder();
	}

	void preOrder()
	{
		if (this == nullptr)
			return;

		cout << this->data << " ";

		this->left->preOrder();
		this->right->preOrder();
	}

	vector<int> preOrderVectorReturnVariant()
	{
		vector<int> ans;
		if (this == nullptr)
			return ans;

		ans.push_back(this->data);

		vector<int> l = this->left->preOrderVectorReturnVariant();
		vector<int> r = this->right->preOrderVectorReturnVariant();

		ans.insert(ans.end(), l.begin(), l.end());
		ans.insert(ans.end(), r.begin(), r.end());

		return ans;
	}
};

class binaryTree
{
private:
	binaryTreeNode* root;

public:

	~binaryTree()
	{
		delete root;
	}

	binaryTree() : root(new binaryTreeNode()) {}

	void inputBT()
	{
		root = root->Input();
	}

	void printBT()
	{
		root->btPrint();
	}

	void LinePrint()
	{
		root->printLevelWise();
	}

	void LineInput()
	{
		root = root->lineWiseInput();
	}

	int nodeCount()
	{
		return root->numberOfNodes();
	}

	void preorder()
	{
		root->preOrder();
	}

	void inorder()
	{
		root->inOrder();
	}

	void postorder()
	{
		root->postOrder();
	}

	vector<int> preOrderVector()
	{
		return root->preOrderVectorReturnVariant();
	}
};

#endif // !BINARYTREE_H

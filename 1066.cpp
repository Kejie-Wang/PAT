#include <iostream>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
	Node(){ left = right = nullptr; }
};

int height(Node* root)
{
	if (root == nullptr)
		return -1;
	else
	{
		int l = height(root->left);
		int r = height(root->right);
		return l > r ? l + 1 : r + 1;
	}
}

Node* LL(Node* k1)
{
	Node* k2;

	k2 = k1->left;
	k1->left = k2->right;
	k2->right = k1;

	return k2;
}

Node* RR(Node* k1)
{
	Node* k2;

	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;

	return k2;
}

Node* LR(Node* k3)
{
	k3->left = RR(k3->left);

	return LL(k3);
}

Node* RL(Node* k3)
{
	k3->right = LL(k3->right);

	return RR(k3);
}

Node* Insert(Node* root, int value)
{
	if (root == nullptr)
	{
		Node* node = new Node;
		node->value = value;
		return node;
	}
	else if (value < root->value)
	{
		root->left = Insert(root->left, value);
		if (height(root->left) - height(root->right) == 2)
		{
			if (value < root->left->value)
				root = LL(root);
			else
				root = LR(root);
		}
		return root;
	}
	else
	{
		root->right = Insert(root->right, value);
		if (height(root->right) - height(root->left) == 2)
		{
			if (value > root->right->value)
				root = RR(root);
			else
				root = RL(root);
		}
		return root;
	}
}


int main()
{
	int n;
	cin >> n;

	Node* root = nullptr;
	for (int i = 0; i < n; i++)
	{
		int value;
		cin >> value;
		root = Insert(root, value);
	}

	cout << root->value;
}
#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int value;
	Node* left;
	Node* right;
};

int sequence[1000];
vector<int> inSequence;
vector<int> postSequence;
bool isMirror = false;

Node* ConstrutTree(int left, int right)
{
	if (left == right)
		return nullptr;

	Node* root = new Node;
	root->value = sequence[left];
	int index;
	if (isMirror)	//mirror BST
	{
		for (index = left + 1; index < right; index++)
			if (sequence[index] < sequence[left])
				break;
	}
	else	//BST
	{
		for (index = left + 1; index < right; index++)
			if (sequence[index] >= sequence[left])
				break;
	}
	root->left = ConstrutTree(left + 1, index);
	root->right = ConstrutTree(index, right);

	return root;
}

void InOrderTraversal(Node* root)
{
	if (root == nullptr)
		return;
	InOrderTraversal(root->left);
	inSequence.push_back(root->value);
	InOrderTraversal(root->right);
}

void PostOrderTraversal(Node* root)
{
	if (root == nullptr)
		return;
	PostOrderTraversal(root->left);
	PostOrderTraversal(root->right);
	postSequence.push_back(root->value);
}

int main()
{
	int nodeNum;
	cin >> nodeNum;
	for (int i = 0; i < nodeNum; i++)
		cin >> sequence[i];

	//judge if it is the mirror of BST
	if (nodeNum>1 && sequence[1] > sequence[0])
		isMirror = true;

	Node* root = ConstrutTree(0, nodeNum);
	InOrderTraversal(root);
	PostOrderTraversal(root);
	bool flag1 = true, flag2 = true;
	for (int i = 1; i < inSequence.size(); i++)
	{
		if (inSequence[i] < inSequence[i - 1])
			flag1 = false;
		if (inSequence[i] > inSequence[i - 1])
			flag2 = false;
		if (!flag1&&!flag2)
			break;
	}
		
			
	if (flag1 || flag2)
	{
		cout << "YES" << endl;
		for (int j = 0; j < postSequence.size() - 1; j++)
			cout << postSequence[j] << " ";
		cout << postSequence.back();
	}
	else
		cout << "NO";		
}
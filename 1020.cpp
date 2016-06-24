#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(){ val = 0; left = right = nullptr; }
};

static int postOrder[30];
static int inOrder[30];

int InOrderFindIndex(int val, int inLeft, int inRight)
{
	for (int i = inLeft; i < inRight; i++)
		if (inOrder[i] == val)
			return i;
}

Node* ConstructTree(int postLeft, int postRight, int inLeft, int inRight)
{
	if (postLeft == postRight)
		return nullptr;

	Node* root = new Node;
	root->val = postOrder[postRight-1];
	int index = InOrderFindIndex(root->val, inLeft, inRight);
	int leftLength = index - inLeft;
	int rightLength = inRight - index - 1;
	root->left = ConstructTree(postLeft, postLeft + leftLength, inLeft, index);
	root->right = ConstructTree(postLeft + leftLength, postRight - 1, index + 1, inRight);

	return root;
}

void LevelOrderTraversal(Node* root, int NodeNum)
{
	queue<Node*> que;
	que.push(root);
	int cnt = 0;
	while (!que.empty())
	{
		Node* last = que.front();
		que.pop();
		cout << last->val;
		++cnt;
		if (cnt < NodeNum)
			cout << " ";
		if (last->left)
			que.push(last->left);
		if (last->right)
			que.push(last->right);
	}

	
}

int main()
{
	int NodeNum;
	cin >> NodeNum;

	for (int i = 0; i < NodeNum; i++)
		cin >> postOrder[i];
	for (int i = 0; i < NodeNum; i++)
		cin >> inOrder[i];

	Node* root;

	root = ConstructTree(0, NodeNum, 0, NodeNum);
	LevelOrderTraversal(root, NodeNum);
}
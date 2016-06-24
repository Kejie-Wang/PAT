#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct Node
{
    int value;
    int left = 0;
    int right = 0;
};

Node tree[31];    //we use tree[0] to devote the null pointer
int treeroot;

void PostTraversal(int root)
{
    if (tree[root].value == 0)
        return;
    PostTraversal(tree[root].left);
    PostTraversal(tree[root].right);
    cout << tree[root].value;
    if (tree[root].value != treeroot)
        cout << " ";
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;

    string op, lastOp;
    int value, lastValue, root;
    cin >> op >> value;    //fist operation must be push
    //construct the tree
    treeroot = root = value;
    tree[value].value = value;
    s.push(value); 
    lastOp = "Push";
    lastValue = value;
    n *= 2;
    while (--n)
    {
        cin >> op;
        if (op == "Push")    //push
        {
            cin >> value;
            tree[value].value = value;
            s.push(value);
            if (lastOp == "Push")
                tree[lastValue].left = value;
            else
                tree[lastValue].right = value;
            lastValue = value;
            lastOp = "Push";
        }
        else    //pop
        {
            lastValue = s.top();
            s.pop();    
            lastOp = "Pop";
        }
    }

    PostTraversal(root); 
}
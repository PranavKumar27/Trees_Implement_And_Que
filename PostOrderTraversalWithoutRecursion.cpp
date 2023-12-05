#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
       data = val;
       left = right = NULL;
    }
};

void postOrder(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;


    Node* cur;
    s1.push(root);
    while(!s1.empty())
    {
        cur =  s1.top();
        s1.pop();
        s2.push(cur);

        Node* leftNode = cur->left;
        if(leftNode)
        {
            s1.push(leftNode);
        }

        Node* rightNode = cur->right;
        if(rightNode)
        {
            s1.push(rightNode);
        }
    }

    while(!s2.empty())
    {
        cur=s2.top();
        s2.pop();
        cout << cur->data << "\t";
    }
    cout << endl;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->right = new Node(9);
    root->right->left = new Node(15);

    postOrder(root);

    return 0;
}

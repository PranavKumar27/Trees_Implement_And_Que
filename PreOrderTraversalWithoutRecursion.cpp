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

void preOrder(Node* root)
{
    stack<Node*> s;
    s.push(root);
    Node* temp;

    while(true)
    {
        if(s.empty())
        {
            break;
        }

        temp =  s.top();
        s.pop();
        cout << "\t" << temp->data;

        if(temp->right)
        {
            s.push(temp->right);
        }
        if(temp->left)
        {
            s.push(temp->left);
        }
    }

}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->right = new Node(9);
    root->right->left = new Node(15);

    preOrder(root);

    return 0;
}

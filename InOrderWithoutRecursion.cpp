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
        left=right=NULL;
    }
};

void printInOrder(Node* root)
{
    cout << __FUNCTION__ << endl;
    stack<Node*> s;
    Node* temp = nullptr;
    Node* prevTemp = nullptr;
    s.push(root);
    temp=root;
    while(temp!=NULL || !s.empty())
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;

        }
        temp = s.top();
        s.pop();
        if(temp!=NULL)
        cout << "\t"  << temp->data;


        temp= temp->right;


    }
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(25);

    printInOrder(root);

    return 0;
}


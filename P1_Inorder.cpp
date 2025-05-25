#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node* prepare_A_Tree()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);


    root->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    return root;
}

void InOrder(Node* root)
{
    if(root==nullptr)
        return;

    InOrder(root->left);
    cout << root->data << ",";
    InOrder(root->right);
}
int main()
{
    cout << "InOrder Traversal" << endl;
    Node* root = prepare_A_Tree();
    InOrder(root);

    return 0;
}

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node(){}
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* deleteNodesInRange(Node* root,int minimum, int maximum)
{
    if(root == nullptr)
        return root;

    root->left = deleteNodesInRange(root->left,minimum,maximum);
    root->right = deleteNodesInRange(root->right,minimum,maximum);

    if(root->data < minimum)
    {
        Node* rchild = root->right;
        //delete(root);
        return rchild;
    }

    if(root->data > maximum)
    {
        Node* lchild = root->left;
        //delete(root);
        return lchild;
    }
    return root;

}

void inOrder(Node* root)
{
    if(!root)
        return;

    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}
int main()
{
    Node* root = new Node(6);
    root->left = new Node(-13);
    root->right = new Node(14);

    root->left->right = new Node(-8);
    root->right->left = new Node(13);
    root->right->right = new Node(15);

    root->right->left->left = new Node(7);

    int r1=-10;
    int r2=13;
    cout << "Before delete in Range:" << r1 << "," << r2 << endl;
    inOrder(root);

    root = deleteNodesInRange(root,r1,r2);

    cout << "\nAfter delete in Range:" << r1 << "," << r2 << endl;
    inOrder(root);


    return 0;
}

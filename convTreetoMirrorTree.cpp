#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;
    Node(int n)
    {
        data = n;
        left = right =NULL;
    }
    Node(){}
};

void mirrorTree(Node* root)
{
    if(root==NULL)
        return;

    Node* leftSubtree = root->left;
    Node* rightSubTree = root->right;

    root->left = rightSubTree;
    root->right = leftSubtree;

    mirrorTree(root->left);
    mirrorTree(root->right);

}

void inOrder(Node* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << "\t";
    inOrder(root->right);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left =  new Node(6);
    root->right->right = new Node(7);

    cout << "Input Tree:\t" ;
    inOrder(root);
    cout << endl;

    mirrorTree(root);

    cout << "Mirror Tree:\t" ;
    inOrder(root);
    cout << endl;

    return 0;
}

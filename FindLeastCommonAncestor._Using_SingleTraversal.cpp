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
        left=right=nullptr;
    }
};

Node* findLeastCommonAncestor(Node* root,int n1, int n2)
{
    if(root == nullptr)
        return nullptr;

    if(root->data == n1 || root->data == n2)
        return root;

    Node* leftRoot = findLeastCommonAncestor(root->left,n1,n2);
    Node* rightRoot = findLeastCommonAncestor(root->right,n1,n2);

    if(leftRoot && rightRoot)
        return root;

    return (root->left)?root->left:root->right;
}

bool IsFound(Node* root,int n)
{
    if(root==nullptr)
        return false;
    if(root->data == n ||
       IsFound(root->left,n) ||
       IsFound(root->right,n) )
    {
        return true;
    }
    return false;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(6);

    int n1 = 3;
    int n2 = 5;

    if(IsFound(root,n1) && IsFound(root,n2))
    {
        Node* res = findLeastCommonAncestor(root,n1,n2);

        if(res)
        {
            cout << "Least Common Ancestor of (" << n1 << "," << n2 << ")= \t" << res->data << endl;
        }
        else
            cout << "Res is NULL" << endl;
    }
    else
    {
         cout << "Least Common Ancestor of (" << n1 << "," << n2 << ")= \t Undefined as Node not found" << endl;
    }
    return 0;
}

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
        left = right = NULL;
    }
    Node(){}
};

bool IsSelfMirror(Node* root1,Node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;

    if( root1 && root2 && root1->data==root2->data)
    {
        return IsSelfMirror(root1->left,root2->right) && IsSelfMirror(root1->right,root2->left);
    }

    return false;
}

bool IsSymetric(Node* root)
{
    return IsSelfMirror(root,root);
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->right = new Node(3);
    root->right->left = new Node(4);

    bool res = IsSymetric(root);

    cout << "Is Tree Symetric=" << res << endl;
    return 0;
}

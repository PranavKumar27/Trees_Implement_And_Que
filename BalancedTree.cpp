#include <iostream>
#include <limits.h>

#define kOne 1
using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node(int d)
    {
        data = d;
        left=right=NULL;
    }
};
int height(Node* root,bool& isBalanced)
{
    if(root == NULL || isBalanced==false)
        return 0;

    int lh = height(root->left,isBalanced);
    int rh = height(root->right,isBalanced);
    cout << "root=" << root->data << "\t lh=" << lh << "\t rh=" << rh << endl;

    if(abs(lh-rh)>kOne)
        isBalanced = false;
    return max(lh,rh)+1;
}
/*
bool isTreeHeightBalanced(Node* root)
{
    if(root == NULL)
        return true;

    int lh = height(root->left);
    int rh = height(root->right);

    cout << "root=" << root->data << "\t lh=" << lh << "\t rh=" << rh << endl;
    if(abs(lh-rh)>kOne)
        return false;

    return isTreeHeightBalanced(root->left) && isTreeHeightBalanced(root->right);
}
*/

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(7);

    bool isBalanced = true;

    //bool res = isTreeHeightBalanced(root)

    height(root,isBalanced);

    cout << "Is Tree Height Balanced =" << isBalanced << endl;


    return 0;
}

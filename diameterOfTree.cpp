#include <iostream>
#include <limits.h>

using namespace std;

int maxi=INT_MIN;
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

int height(Node* root,int& dia)
{
    if(root == NULL)
        return 0;
    int lh = height(root->left,dia);
    int rh = height(root->right,dia);
    if(dia<lh+rh+1)
        dia = lh+rh+1;
    return max(lh,rh)+1;
}

void diameter(Node* root)
{
    /*
    if(root == NULL)
        return;

    int lh = height(root->left);
    int rh = height(root->right);

    cout << "Root=" << root->data <<  "\tlh=" << lh << "\t rh =" << rh << "\tBefore maxi=" << maxi << endl;
    if(maxi<(lh+rh))
    {
        maxi = lh+rh;
    }
    cout << "After maxi=" << maxi << endl;
    diameter(root->left);
    diameter(root->right);
    */
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);


    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);

    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);

    root->right->left->left->right = new Node(10);

    root->right->left->left->right->left = new Node(12);

    root->right->right->left->left = new Node(11);

    root->right->right->left->left->right = new Node(14);

    //diameter(root);
    int dia = 0;
    height(root,dia);

    cout << "diameter of Tree =" << dia << endl;

    return 0;
}

// Childen Sum Parent Problem Link: https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/

#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* left,*right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool IsSumTree(Node* root)
{
    if(root == NULL)
        return true;

    cout << __FUNCTION__ << "\troot->data=" << root->data << endl;
    Node* leftSubTree = root->left;
    Node* rightSubTree = root->right;
    int l,d,r;
    if(root)
        d = root->data;
    if(leftSubTree)
        l = leftSubTree->data;
    if(rightSubTree)
        r = rightSubTree->data;

    if(leftSubTree==NULL && rightSubTree==NULL)
    {
        cout << "left Right NULL" << endl;
        return true;
    }
    else if(leftSubTree!=NULL && rightSubTree==NULL && l != d)
    {
        cout << "left Not NULL l="<< l << "\td=" << d << endl;
        return false;
        //return IsSumTree(leftSubTree);
    }
    else if(leftSubTree==NULL && rightSubTree!=NULL && r != d)
    {
        cout << "right Not NULL r="<<r << "\td=" << d << endl;
        return false;
        //return IsSumTree(rightSubTree);
    }
    else if(leftSubTree && rightSubTree && l+r!=d)
    {
        cout << "Left & right Not NULL l="<<l  << "\tr=" <<r << "\td=" << d << endl;
        return false;

    }
    return IsSumTree(leftSubTree) && IsSumTree(rightSubTree);;
}

int IsRootSumOfChild(Node* root)
{
    if(root==NULL || root->left==NULL && root->right==NULL)
        return 1;
    else
    {
        int sum =0;
        Node* leftSubTree = root->left;
        Node* rightSubTree = root->right;

        if(leftSubTree)
        {
            sum+=leftSubTree->data;
            cout << "Left Sum=" << sum << endl;
        }
        if(rightSubTree)
        {
            sum+=rightSubTree->data;
            cout << "Right Sum=" << sum << endl;
        }
        if(sum==root->data)
        {
            cout << "Sum=" << sum << endl;
            return IsRootSumOfChild(leftSubTree)&& IsRootSumOfChild(rightSubTree);
        }
        else
            return 0;
    }
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    /*root->left->right = new Node(5);
    root->right->left = new Node(3);*/

    bool res = IsSumTree(root);
    cout << "IsSumTree =" << res << "-------------" << endl;

    int ans = IsRootSumOfChild(root);
    cout << "IsRootSumOfChild=" << ans << endl;
    return 0;
}

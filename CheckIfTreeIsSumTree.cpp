#include <iostream>
#include <limits.h>

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
        left = right = nullptr;
    }
};

int binarySumTree(Node* root,int& sum)
{
    if(root==nullptr)
    {
        return 0;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        sum += root->data;
        return sum;
    }

    int lSum = 0;
    int rSum = 0;
    int leftSum = binarySumTree(root->left,lSum);
    if(leftSum==-1)
        return -1;
    int rightSum = binarySumTree(root->right,rSum);
    if(rightSum==-1)
        return -1;

    if(leftSum+rightSum == root->data)
    {
        sum = leftSum+rightSum+root->data;
        return sum;
    }
    else
    {
        return -1; // Or Return INT_MIN;
    }
}

int findSum(Node* root)
{
    if(root == nullptr)
        return 0;
    return findSum(root->left)+root->data+findSum(root->right);
}

bool IsBinaryTreeSum(Node* root)
{
    if(root==nullptr ||
       root->left==nullptr && root->right == nullptr)
    {
        return 1;
    }

    int ls = findSum(root->left);
    int rs = findSum(root->right);

    if(ls+rs == root->data)
    {
        return IsBinaryTreeSum(root->left)&& IsBinaryTreeSum(root->right);
    }
    return 0;
}
int main()
{
    Node* root = new Node(26);

    root->left = new Node(10);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(6);

    root->right->left = new Node(3);
    //root->right->right = new Node(5);

    int sum = 0;
    int res = binarySumTree(root,sum);

    cout << "sum=" << sum << "\t res=" << res << endl;
    if(res == sum && sum!=0)
    {
        cout << "Binary Tree is a Sum Tree" << endl;
    }
    else
    {
        cout << "Binary Tree is not a Sum Tree" << endl;
    }

    bool ans = IsBinaryTreeSum(root);

    if(ans)
    {
        cout << "Binary Tree is a Sum Tree" << endl;
    }
    else
    {
        cout << "Binary Tree is not a Sum Tree" << endl;
    }

    return 0;
}

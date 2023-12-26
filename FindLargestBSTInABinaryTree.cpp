#include <iostream>
#include <limits.h>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(){}

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct BST{
     int sz;
     int max_val;
     int min_val;
     int ans;
     bool isBST;
     };

BST findLargestBST(Node* root)
{
    if(root == NULL)
        return {0,INT_MIN,INT_MAX,0,true}; // Not Here max_val on left is assumed to be INT_MIN since we compare as left < root->data < right
                                            // INT_MIN  < root->data  < right_data    if left subtree is NULL
                                            // left_data < root->data < INT_MAX      if right subtree is NULL

    if(root->left == NULL && root->right == NULL)
        return {1,root->data,root->data,1,true};

    BST l = findLargestBST(root->left);
    BST r = findLargestBST(root->right);

    BST res;
    if( l.isBST && r.isBST &&
        l.max_val < root->data &&
        r.min_val > root->data )
    {
        res.sz = l.sz + r.sz + 1;
        res.max_val = max(r.max_val,root->data);
        res.min_val = min(l.min_val,root->data);
        res.ans = l.ans + r.ans + 1;
        res.isBST = true;
    }
    else
    {
        res.ans = max(l.ans,r.ans);
        res.isBST = false;
    }
    return res;
}
int main()
{
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);


    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);

    BST res = findLargestBST(root);

    cout << "Result = " << res.ans << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;


    Node(int val)
    {
        data=val;
        left=right=NULL;
    }

};

// Reverse Inroder Traversal
void MorrisTraversal(Node* root,vector<int>& v)
{
    if(!root)
        return;
    MorrisTraversal(root->right,v);
    v.push_back(root->data);
    MorrisTraversal(root->left,v);
}

void MorrisTraversal(Node* root,int k, int& p,int& ans)
{
    if(!root || k<p )
        return;
    MorrisTraversal(root->right,k,p,ans);

    if(k==p)
    {
        ans = root->data;
        p++;
        return;
    }
    else
    {
        p++;
    }

    //v.push_back(root->data);
    MorrisTraversal(root->left,k,p,ans);
}

int main()
{
    Node* root =  new Node(10);
    root->left = new Node(4);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->right->left = new Node(15);
    root->right->right = new Node(40);

    int K = 3;
    vector<int>v;
    MorrisTraversal(root,v);

    cout << K <<"-th Largest Elements in BST=" << v[K-1] << endl;

    int p=0;
    int ans = -1;
    MorrisTraversal(root,K-1,p,ans);

    cout << K <<"-th Largest Elements in BST Using Technique 2=" << ans << endl;
    return 0;
}


// Kth Smallest 

void InOrder(TreeNode* root,vector<int>& v)
    {
        if(!root)
        {
            return;
        }
        InOrder(root->left,v);
        v.push_back(root->val);
        InOrder(root->right,v);
    }

    void InOrder(TreeNode* root,int k, int& p,int& ans)
    {
        if(!root || k<p)
        {
            return;
        }
        InOrder(root->left,k,p,ans);
        if(k==p)
        {
            ans = root->val;
            p++;
            return;
        }
        else
        {
            p++;
        }
        //v.push_back(root->val);
        InOrder(root->right,k,p,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        //InOrder(root,v);

        int p=0;
        int ans=-1;

        InOrder(root,k-1,p,ans);
        //cout << "ans=" << ans << endl;
        return ans;   
    }

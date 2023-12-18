#include <iostream>
#include <queue>
#include <vector>
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
        left = right = NULL;
    }
};

void print_v(vector<int>v)
{
    for(auto x:v)
    {
        cout << x << "\t";
    }
    cout << endl;
}

void findAllLeafNodes(Node* root,vector<int>& leaf)
{
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
            Node* temp = q.front();
            q.pop();

            if(temp->left == NULL && temp->right == NULL)
            {
                leaf.push_back(temp->data);
                continue;
            }
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    print_v(leaf);
}

bool findPath(Node* root,int n,vector<int>& path)
{
    if(root==NULL)
        return false;

    path.push_back(root->data);

    if(root->data == n)
        return true;

    if(root->left && findPath(root->left,n,path) ||
       root->right && findPath(root->right,n,path))
        return true;

    path.pop_back();
    return false;

}

int generatePathSumFromRoot(Node* root,int n)
{
    int sum=0;
    vector<int> path;
    findPath(root,n,path);

    for(auto s:path)
    {
        sum = sum+s;
    }
    return sum;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(7);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->right = new Node(9);
    root->left->left->left = new Node(3);

    vector<int> leaf;
    findAllLeafNodes(root,leaf);

    int maxleaf = INT_MIN;
    for(auto s:leaf)
    {
        int sum = generatePathSumFromRoot(root,s);
        if(maxleaf<sum)
        {
            maxleaf = sum;
        }
    }

    cout << "Result = " << maxleaf << endl;

    return 0;
}

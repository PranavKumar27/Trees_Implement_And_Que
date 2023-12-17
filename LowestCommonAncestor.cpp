#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Node
{
public:
    int data;
    Node*left,*right;

    Node(){}
    Node(int val)
    {
        data = val;
        left=right=NULL;
    }
};

void print_v(vector<int>v)
{
    for(auto i:v)
    {
        cout << i << "\t";
    }
    cout << endl;
}
bool findPath(Node* root,vector<int>&path,int n2)
{
    cout << "====================" << __FUNCTION__ << "====================" << endl;
    if(root == NULL)
        return false;

    path.push_back(root->data);
    print_v(path);
    if(root->data == n2)
        return true;

    if(root->left && findPath(root->left,path,n2) ||
       root->right && findPath(root->right,path,n2))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int findLCA(Node* root,int n1,int n2)
{
    if(root == NULL)
        return -1;

    vector<int>path1;
    vector<int>path2;

    if(!findPath(root,path1,n1)||!findPath(root,path2,n2))
        return -1;

    int i=0;
    for(i=0;i<path1.size() && i<path2.size();i++)
    {
        if(path1[i]!=path2[i])
        {
            break;
        }
    }
    return path1[i-1];
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    int n1 = 6;
    int n2 = 8;
    int res;
    res = findLCA(root,n1,n2);
    cout << "Least Common Ancestor of node1 =" << n1 << " And node2 =" << n2 << " is equal to "<< res << endl;
    return 0;
}

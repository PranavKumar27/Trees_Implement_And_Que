#include <iostream>
#include <map>
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
       data = val;
       left = right = NULL;
    }
};

void horizontalDistanceOfNodes(map<int,vector<int>>& Mp,int ht, Node* root)
{

    if(root==NULL)
    {
        return;
    }

    vector<int>v;
    v.push_back(root->data);
    Mp[ht].push_back(root->data);

    cout << "root->data=" << root->data << endl;
    horizontalDistanceOfNodes(Mp,ht-1, root->left);

    horizontalDistanceOfNodes(Mp,ht+1, root->right);

}

void VerticalOrder(Node* root)
{
    map<int,vector<int>> Mp;
    int ht=0;
    horizontalDistanceOfNodes(Mp,ht,root);

    // Print map
    for(auto i:Mp)
    {
        for(auto j:i.second)
        {
            cout << "\t" << j;
        }
        cout << endl;
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->right = new Node(9);
    root->right->left = new Node(15);

    VerticalOrder(root);

    return 0;
}

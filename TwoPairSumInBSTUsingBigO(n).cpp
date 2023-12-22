#include <iostream>
#include <vector>

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

void InOrderList(Node* root,vector<int>&v)
{
    if(root == nullptr)
        return ;

    InOrderList(root->left,v);
    v.push_back(root->data);
    InOrderList(root->right,v);
}


bool IsSumPairPossible(Node* root,int key)
{
    if(root==nullptr)
        return false;

    int start = 0;
    vector<int> v;
    InOrderList(root,v);
    int last = v.size()-1;

    while(start<last) // Ideally it should be start equal to last But if we have only 1 element in Tree, No need to enter inside while
                        // Since start=last means only one element in Tree and there cannot be such pairs.
    {
        int sum = v[start]+v[last];
        if(sum == key)
        {
            cout << "Pair=" << v[start] << "," << v[last] << endl;
            return true;
        }
        else if(sum>key)
        {
            last = last-1;
        }
        else
        {
            start = start+1;
        }
    }

    return false;
}


int main()
{
    Node* root = new Node(15);

    root->left = new Node(10);
    root->right = new Node(20);

    root->left->left = new Node(8);
    root->left->right = new Node(12);


    root->right->left = new Node(20);
    root->right->right = new Node(25);

    int key = 23;
    bool ans = IsSumPairPossible(root,key);
    cout << "Result=" << ans << endl;
    return 0;
}

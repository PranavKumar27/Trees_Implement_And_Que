#include <iostream>
#include <vector>
#include <algorithm>

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

void inOrderList(Node* root,vector<int>& v)
{
    if(root == NULL)
        return;
    inOrderList(root->left,v);
    v.push_back(root->data);
    inOrderList(root->right,v);
}


void inOrderList(Node* root,vector<int> sumV,int& idx)
{
    if(root == NULL)
        return;
    inOrderList(root->left,sumV,idx);
    //cout << "Data =" << root->data << " is replaced with data=" << sumV[idx] << endl;
    root->data = sumV[idx++];
    inOrderList(root->right,sumV,idx);
}

void modifyTreeWithSumTree(Node* root,int& sum)
{
    if(root == nullptr)
        return;

    modifyTreeWithSumTree(root->right,sum);
    //int old_data = root->data;
    //root->data = sum;
    //sum = sum+old_data;

    sum =  sum +root->data;
    root->data = sum - root->data;

    modifyTreeWithSumTree(root->left,sum);
}

int main()
{
    Node* root = new Node(11);

    root->left = new Node(2);
    root->right = new Node(29);


    root->left->left = new Node(1);
    root->left->right = new Node(7);

    root->right->left = new Node(15);
    root->right->right = new Node(40);

    root->right->right->left = new Node(35);

    /*
    vector<int> v;
    inOrderList(root,v);

    cout << "Input Inorder:\t";
    for(auto x:v)
    cout << x << "\t";
    cout << endl;
    // reverse the vector
    vector<int> rev(v);
    reverse(rev.begin(),rev.end());

    cout << "Reverse Inorder:\t";
    for(auto x:rev)
    cout << x << "\t";
    cout << endl;

    vector<int> res;
    int sz = v.size()-1;
    for(int j=0;j<=sz;j++)
    {
        res.push_back(0);
    }
    int i;
    for(i=1;i<=sz;i++)
    {
        res[i]=res[i-1]+rev[i-1];
    }
    cout << "Resultant Sum Inorder:\t";
    for(auto x:res)
        cout << x << "\t";
    cout << endl;

    vector<int> Resrev(res);
    reverse(Resrev.begin(),Resrev.end());

    int idx = 0;
    inOrderList(root,Resrev,idx);

    vector<int> v2;
    inOrderList(root,v2);

    cout << "Result Inorder:\t";
    for(auto x:v2)
    cout << x << "\t";
    cout << endl;
    */

    int sum_Data = 0;
    modifyTreeWithSumTree(root,sum_Data);

    vector<int> v2;
    inOrderList(root,v2);

    cout << "Result Inorder:\t";
    for(auto x:v2)
    cout << x << "\t";
    cout << endl;

    return 0;
}

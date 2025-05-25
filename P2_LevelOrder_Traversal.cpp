#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// This is a BFS Based Technique of Tree Traversal

class Node
{
public:
    int data;
    Node* left,*right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node* prepare_A_Tree()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);


    root->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    return root;
}

vector<vector<int>> levelOrderTraversal(Node* root)
{
    vector<vector<int>> Ans;
    if(root == nullptr)
        return Ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        vector<int> v;
        int sz = q.size();
        for(int i=0;i<sz;i++)
        {
           Node* Front = q.front();
           v.push_back(Front->data);
           q.pop();
           if(Front->left!=nullptr)
            q.push(Front->left);
           if(Front->right!=nullptr)
            q.push(Front->right);
        }
        Ans.push_back(v);
    }
    return Ans;
}

void print_v(vector<int>& v)
{
    for(auto d:v)
    {
        cout << d << ",";
    }

}

void print_v_of_v(vector<vector<int>> VV)
{
    for(auto v:VV)
    {
        cout << "{ ";
        print_v(v);
        cout << " }";
        cout << endl;
    }
}
int main()
{
    cout << "InOrder Traversal" << endl;
    Node* root = prepare_A_Tree();
    vector<vector<int>> Ans = levelOrderTraversal(root);

    print_v_of_v(Ans);

    return 0;
}

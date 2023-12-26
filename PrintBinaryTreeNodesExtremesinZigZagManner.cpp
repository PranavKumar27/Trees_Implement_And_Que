#include <iostream>
#include <vector>
#include <queue>

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

void print_v(vector<int> v)
{
    cout << endl;
    for(auto d:v)
    {
        cout << d << "\t";
    }
    cout << endl;
}


vector<int> findNodeExtremes(Node* root)
{
    if(root == NULL)
    return {};

    vector<int> res;
    queue<Node*>q;
    q.push(root);
    bool flag = false;
    while(!q.empty())
    {
        int sz = q.size();
        for(int i=sz-1;i>=0;i--)
        {
            Node* temp = q.front();
            q.pop();

            if(!flag && i==0)
                res.push_back(temp->data);
            if(flag && i==sz-1)
                res.push_back(temp->data);

            if(temp->left)
            {
                q.push(temp->left);
            }


            if(temp->right)
                q.push(temp->right);

        }
        flag = !flag;
    }
    return res;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    root->left->left->left  = new Node(8);
    root->left->left->right  = new Node(9);
    root->left->right->left  = new Node(10);
    root->left->right->right  = new Node(11);
    root->right->right->left  = new Node(14);
    root->right->right->right  = new Node(15);

    root->left->left->left->left  = new Node(16);
    root->left->left->left->right  = new Node(17);
    root->right->right->right->right  = new Node(31);

    vector<int> res = findNodeExtremes(root);
    print_v(res);

 return 0;
}

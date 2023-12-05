#include <iostream>
#include <stack>
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
        left=right=NULL;
    }
};

void printInOrder(Node* root)
{
    cout << __FUNCTION__ << endl;
    stack<Node*> s;
    Node* temp;
    temp=root;

    while(temp!=NULL || !s.empty())
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        temp = s.top();
        s.pop();

        if(temp!=NULL);
        cout << "\t"  << temp->data;

        if(temp!=NULL)
            temp = temp->right;
    }
    cout << endl;
}

 vector<int> inorderTraversal(Node* root)
 {
     cout << __FUNCTION__ << endl;
     vector<int> res;

        Node* temp = root;
        stack<Node*> s;

        while(true)
        {
            if(temp!=NULL)
            {
                s.push(temp);
                temp=temp->left;
            }
            else
            {
                if(s.empty())
                {
                    break;
                }

                temp=s.top();
                res.push_back(temp->data);
                s.pop();

                temp = temp->right;
            }
        }
        return res;
    }
int main()
{
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(25);

    printInOrder(root);

    vector<int> v;
    v = inorderTraversal(root);

    for(auto i:v)
    {
        cout << "\t" << i ;
    }
    cout << endl;

    return 0;
}


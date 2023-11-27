#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

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
        data =  val;
        left = right = NULL;
    }
};

void print_v(vector<int> v)
{
    for(auto X:v)
    {
        cout << "\t" << X;
    }
    cout << endl;
}

void ZigZagTraversalBTree(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    vector<int>ans;
    queue<Node*> q;
    q.push(root);
    bool toggle = false; // False indicates Left to right

    while(!q.empty())
    {
        int sz=q.size();
        vector<int>level;
        //cout << "sz=" << sz << endl;
        for(int i=0;i<sz;i++)
        {
            Node* temp = q.front();
            q.pop();
            level.push_back(temp->data);

            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            //print_v(level);
        }
        toggle=!toggle;
        if(toggle == false)
        {
            //cout << "\nReversing Vector" << endl;
            reverse(level.begin(),level.end());
            //print_v(level);
        }
        for(int i=0;i<level.size();i++)
        {
            //cout << "\nData Inserted in ans Vector" << endl;

            ans.push_back(level[i]);
        }
    }
    print_v(ans);
}



int main()
{
    Node* root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    ZigZagTraversalBTree(root);

    return 0;
}


// Optimized Code /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <algorithm>

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(!root)
        {
            return {};
        }
        vector<vector<int>> ans;
        bool toggle=false;
        queue<TreeNode*> q;
        q.push(root);
        int index;

        while(!q.empty())
        {
            int sz=q.size();
            vector<int>v(sz);
            for(int i=0;i<sz;++i)
            {
                TreeNode* temp = q.front();
                q.pop();
                // if(temp==NULL)
                //     continue;
                // v.push_back(temp->val);
                index = (!toggle)?i:sz-1-i;
                v[index] = temp->val;
                //cout << "Size of v" << v.size() << endl;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }

            toggle=!toggle;
            // if(toggle==false)
            // {
            //     reverse(v.begin(),v.end());
            // }
            ans.push_back(v);
        }

        // for (auto i:ans)
        // {
        //     for(auto j:i)
        //     {
        //         cout << "\t" << j;
        //     }
        //     cout << endl;
        // }
        return ans;
        
    }
};


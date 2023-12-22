#include <iostream>
#include <stack>

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

bool findTwoPairSumUsingStacks(Node* root,int iSum)
{
    cout << __FUNCTION__ << endl;
    bool done1 = false;
    bool done2 = false;
    Node* cur1=root;
    Node* cur2=root;
    stack<Node*> s1;
    stack<Node*> s2;
    int val1,val2;

    if(root==nullptr)
        return false;

    while(1)
    {
        cout << "done1=" << done1 << "\t done2=" << done2 << endl;
        while(done1== false)
        {
            if(cur1!=NULL)
            {
                s1.push(cur1);
                cout << "Pushed in Stack1 data=" << cur1->data << endl;
                cur1 = cur1->left;
            }
            else
            {
                if(s1.empty())
                    done1 = true;
                else
                {
                    cur1 = s1.top();
                    cout << "Popped from Stack1 data=" << cur1->data << endl;
                    s1.pop();
                    val1 = cur1->data;
                    cout << "val1=" << val1 << endl;
                    cur1 = cur1->right;
                    done1 = true;
                }
            }
        }


        while(done2== false)
        {
            if(cur2!=NULL)
            {
                s2.push(cur2);
                cout << "Pushed in Stack2 data=" << cur2->data << endl;
                cur2 = cur2->right;
            }
            else
            {
                if(s2.empty())
                    done2 = true;
                else
                {
                    cur2 = s2.top();
                    cout << "Popped from Stack2 data=" << cur2->data << endl;
                    s2.pop();
                    val2 = cur2->data;
                    cout << "val2=" << val2 << endl;
                    cur2 = cur2->left;
                    done2 = true;
                }
            }
        }

        int calculatedSum = val1+val2;
        cout << "val1=" << val1 << " val2=" << val2 <<  " Calculated Sum =" << calculatedSum << endl;
        if( calculatedSum == iSum)
        {
            return true;
        }

        else if(calculatedSum > iSum)
        {
            done2 = false;
        }
        else
        {
            done1 = false;
        }

        if(val1 >= val2)
            return false;
    }

}

int main()
{
    Node* root = new Node(15);

    root->left = new Node(10);
    root->right = new Node(20);

    root->left->left = new Node(8);
    root->left->right = new Node(12);


    root->right->left = new Node(17);
    root->right->right = new Node(25);

    int key = 25;
    bool ans = findTwoPairSumUsingStacks(root,key);
    cout << "Result=" << ans << endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <stack>
#include <climits>

using namespace std;

class Node
{
public:
    int data;
    Node* left,*right;

    Node(){}
    Node(int d)
    {
        data = d;
        left=right=nullptr;
    }
};

void print_v(vector<int> v)
{
    for(auto i:v)
    {
        cout << i << "\t";
    }
    cout << endl;
}

bool IsBstFromPreOrder(vector<int> pre)
{
    //cout << __FUNCTION__ << "\t size=" << pre.size() << endl;
    if(pre.size()==0 || pre.size()==1)
    {
        return true;
    }

    int cur = pre[0];
    int greaterIndx=-1;
    int val = cur;
    for(int i=1;i<pre.size();i++)
    {
        if(pre[i]>cur && val>pre[i])
        {
            greaterIndx = i;
            //break;
            val = pre[i];
        }
    }

    if(greaterIndx == -1 && val == cur && pre.size()==2)
       return 1;
    else if(greaterIndx!=-1 && greaterIndx <= pre.size())
    {
        vector<int>leftVector(pre.begin()+1,pre.begin()+greaterIndx);
        //print_v(leftVector);
        vector<int>rightVector(pre.begin()+greaterIndx+1,pre.end());
        //print_v(rightVector);
        return IsBstFromPreOrder(leftVector) && IsBstFromPreOrder(rightVector);
        //return true;
    }
    else
        return false;
}

bool canRepresentBST(vector<int> pre)
{
    stack<int> s;
    int root=INT_MIN;
    int N = pre.size();

    for(int i=0;i<N;i++)
    {

        if(pre[i] < root)
            return false;

        if(!s.empty() && pre[i]>s.top())
        {
            root = s.top();
            s.pop();
        }

        s.push(pre[i]);
    }
    return true;
}

int main()
{
    vector<int> Pre{3, 2, 6};

    bool res = IsBstFromPreOrder(Pre);
    //cout << "\t  IsBstFromPreOrderres =" << res << endl;


    bool res1 = canRepresentBST(Pre);
    cout << "\t canRepresentBST res =" << res1 << endl;

    return 0;
}

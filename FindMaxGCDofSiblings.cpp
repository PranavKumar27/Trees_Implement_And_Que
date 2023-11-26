#include <iostream>
#include <map>
#include <vector>
#define kZero 0
#define kOne 1
#include <climits>


using namespace std;

void swap(int&a,int&b)
{
    int temp = a;
    a=b;
    b=a;
}

int findGCD(int a, int b)
{
    if(a>b)
    {
        swap(a,b);
    }

    int rem=b%a;
    if(rem == 0)
    {
        return a;
    }
    else
    {
        findGCD(rem,a);
    }
}

int findGCDofSiblings(vector<vector<int>> v,int &ans)
{
    pair<int,int> a = make_pair(v[kZero][kZero],v[kZero][kOne]);
    pair<int,int> b;

    for(int i=1;i<v.size();i++)
    {
        b=make_pair(v[i][kZero],v[i][kOne]);

        if(a.first == b.first)
        {
            ans = max(ans,findGCD(a.second,b.second));
        }
        a=b;
    }
    return ans;
}

int main()
{
    //int arr[1][2]={{1}};
    //int arr[6][2]={{4,5},{4,2},{2,3},{2,1},{3,7},{3,12}};

    int ans=0; // We are setting as 0 instead of INT_MIN since minimum GCD is 0, Negative GCD is not possible
    vector<vector<int>> v;
    v.push_back({4,6});
    v.push_back({4,8});
    v.push_back({8,12});
    cout << "Max GCD of Siblings:" << findGCDofSiblings(v,ans) << endl;

    /*
    int n=1;
    map<int,vector<int>> aMapOfNodes;
    for(int i=0;i<n;i++)
    {
        auto aMapItr = aMapOfNodes.find(arr[i][kZero]);
        if(aMapItr != aMapOfNodes.end())
        {
            (aMapItr->second).push_back(arr[i][kOne]);
        }
        else
        {
            vector<int>v;
            v.push_back(arr[i][kOne]);
            int key=arr[i][kZero];
            aMapOfNodes[key] = v;
        }
    }


    for(auto k:aMapOfNodes)
    {
        cout << "Key:" << k.first << "\t";
        vector<int>v(k.second);
        for(auto m:v)
        {
            cout << "\t" << m << " , ";
        }
        cout << endl;

    }
    int MaxGcd = INT_MIN;
    for(auto i:aMapOfNodes)
    {
        vector<int>v(i.second);
        vector<int>GCDVector;
        for(auto j:v)
        {
            if(aMapOfNodes.find(j)==aMapOfNodes.end())
            {
                GCDVector.push_back(j);
                cout << "Not Found in MAP=" << j << endl;
            }
            else
            {
                cout << "Found in MAP=" << j << endl;
                // Ignore GCD if Found in Map
            }
             //cout << "1 GCD[0]=" << GCDVector[0] << endl;
        }
        cout << "Size of GCD =" << GCDVector.size() << endl;
        //cout << " 1 GCD[0]=" << GCDVector[0] << endl;
        int ObtainedGCD=0;
        if(GCDVector.size()==2)
        {
            ObtainedGCD=findGCD(GCDVector[0],GCDVector[1]);
        }
        else if(GCDVector.size()==1)
        {
            ObtainedGCD = GCDVector[0];
            cout << " 2 GCD[0]=" << GCDVector[0] << endl;
        }

        if(ObtainedGCD>MaxGcd)
        {
            MaxGcd = ObtainedGCD;
        }
        cout << "ObtainedGCD=" << ObtainedGCD << endl;
        cout << "MaxGCD=" << MaxGcd << endl;
    }
*/
    return 0;
}





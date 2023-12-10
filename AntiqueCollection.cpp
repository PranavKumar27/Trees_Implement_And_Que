// Problem Here https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-132/problems


class Solution {
  public:
    int antiqueItems(int n, vector<int> &items, vector<int> &price)
    {
        map<int,vector<int>> Mp;
        
        for(int i=0;i<n;i++)
        {
            auto itr = Mp.find(items[i]);
            if(itr==Mp.end())
            {
                vector<int> v{price[i]};
                Mp[items[i]] = v;
            }
            else
            {
                vector<int>v = itr->second;
                int sz = v.size();
                if(sz>=1)
                {
                    int old_data = v[0];
                    if(old_data > price[i])
                    {
                        v[0] = price[i];
                        v.push_back(old_data);
                    }
                    else
                    {
                        v.push_back(price[i]);
                    }
                    Mp[items[i]] = v;
                }
                
                //sort(v.begin(),v.end());
                
            }
             
        }
        
        int res=0;
        int key,val;
        vector<int> v;
        
        for(auto itr:Mp)
        {
            key = itr.first;
            v = itr.second;
            val = v[0];
            res = res+val;
        }
        //cout << "res=" << res << endl;
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> items(n);
        Array::input(items,n);
        
        
        vector<int> price(n);
        Array::input(price,n);
        
        Solution obj;
        int res = obj.antiqueItems(n, items, price);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends

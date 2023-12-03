#include <iostream>

using namespace std;

// Find Number of Unique BST
// Number of BST is the Result of Catalan Number
// Formula Cn = C0*Cn-1 + C1*Cn-2+...................Cn-1*C0
// C3 = C0*C2 + C1*C1 + C2*C0

int numTrees(int N) 
{
  // Your code here
  long DP[N+1];
  for(int i = 0; i<N+1 ; i++)
  {
    DP[i] = -1;
  }
        
   catalan(N,DP);
   return (int)DP[N];
}
    
long catalan(int n,long DP[])
{
    if(n==0||n==1)
    {
        DP[0]=DP[1]=1;
        return 1;
    }
    
    if(DP[n] != -1)
    {
        return DP[n];
    }
    
    long val=0;
    for(int i=0;i<n;i++)
    {
        val = (val + (catalan(i,DP)*(catalan(n-1-i,DP))%Mod))%Mod;  
    }
    DP[n]=val;
    return DP[n];     
}

int main()
{
    int N;
    cout << "Enter a Number :" << endl;
    cin >> N;
    cout << "Count of Unique BST  Using Catalan Numbers=:" << numTrees(N) << endl;

    return 0;
}

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[k+1];
        for(int i=0;i<k+1;i++){
            dp[i]=i;
        }
        for(int i=2;i<n+1;i++){
            int dp2[k+1]={0};
            int x=1;
            for(int j=1;j<k+1;j++){
                while(x<k && max(dp[x-1],dp2[j-x])>max(dp[x],dp2[j-x-1])){
                    x++;
                }
                dp2[j]=1+max(dp[x-1],dp2[j-x]);
            }
            for(int j=0;j<k+1;j++){
                dp[j]=dp2[j];
            }
        }
        return dp[k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long dp[n+1][m];
        for(long long i=0;i<m;i++){
            dp[0][i]=1;
        }
        for(long long i=1;i<=n;i++){
            for(long long j=0;j<m;j++){
                long long a = (j-1 >= 0) ? dp[i][j-1] : 0;
                long long b = (i-S[j] >= 0) ? dp[i-S[j]][j] : 0;
                dp[i][j] = a + b;
            }
        }
        return dp[n][m-1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
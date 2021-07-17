// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++)
	        dp[i][0]=true;
	    for(int i=1;i<=sum;i++)
	        dp[0][i]=false;
	    int mindiff=INT_MAX;     
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<sum+1;j++){
	            dp[i][j]=dp[i-1][j];
	            if(arr[i-1]<=j)
	                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i-1]];
	        }
	    }
	    for(int i=sum/2;i>=0;i--){
	        if(dp[n][i]==true){
	            mindiff=min(mindiff,abs(sum-2*i));
	        }
	    }
	    return mindiff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends

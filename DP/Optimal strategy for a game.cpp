// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//Function to find the maximum possible amount of money we can win.
long long maximumAmount(int arr[], int n) 
{
    // Your code here
    if(n==0)
        return 0;
    int dp[n][n];
    for(int k=0;k<n;k++){
        for(int i=0, j=k;i<n && j<n;i++, j++){
            if(i==j){
                dp[i][j]=arr[i];
            }
            else if(abs(i-j)==1){
                dp[i][j]=max(arr[i],arr[j]);
            }
            else{
                dp[i][j]=max((arr[i]+min(dp[i+2][j],dp[i+1][j-1])),(arr[j]+min(dp[i][j-2],dp[i+1][j-1]))); 
            }
        }
    }
    return dp[0][n-1];
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends

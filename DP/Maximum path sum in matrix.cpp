// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        if(N==0)
            return 0;
        int dp[N][N];
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                dp[i][j]=Matrix[i][j];
        }
        for(int i=N-2;i>=0;i--){
            for(int j=0;j<N;j++){
                if(j==0)
                    dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
                else if(j==N-1)
                    dp[i][j]+=max(dp[i+1][j-1],dp[i+1][j]);
                else
                    dp[i][j]+=max(max(dp[i+1][j-1],dp[i+1][j]),dp[i+1][j+1]);
            }
        }
        int maxi=dp[0][0];
        for(int i=1;i<N;i++){
            if(maxi<dp[0][i])
                maxi=dp[0][i];
        }
        return maxi;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends

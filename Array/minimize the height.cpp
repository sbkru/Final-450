// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        if(n==1)
             return 0;
        sort(arr,arr+n);
        int res=arr[n-1]-arr[0];
        int mini,maxi;
        int small=arr[0]+k;
        int big=arr[n-1]-k;
        for(int i=0;i<n-1;i++){
            mini=min(small,arr[i+1]-k);
            maxi=max(big,arr[i]+k);
            if(mini < 0)
                continue;
            res=min(res,maxi-mini);
        }
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

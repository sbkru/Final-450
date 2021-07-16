// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    if(n<=1){
	        return arr[0];
	    }
	    long long maxprod=1,prod=1;
	    for(int i=0;i<n;i++){
	        prod=prod*arr[i];
	        if(maxprod<prod){
	            maxprod=prod;
	        }
	        if(arr[i]==0){
	            prod=1;
	        }
	    }
	    prod=1;
	    for(int i=n-1;i>=0;i--){
	        prod=prod*arr[i];
	        if(maxprod<prod){
	            maxprod=prod;
	        }
	        if(arr[i]==0){
	            prod=1;
	        }
	    }
	    return maxprod;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends

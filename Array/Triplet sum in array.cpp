// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here  
        int sum=arr[0];
        int l=0,r=0,count=n+1;
        if(arr[0]>x){
            return 1;
        }
        while(l<=r && r<=n-1){
            if(sum<=x){
                r++;
                sum=sum+arr[r];
            }
            else{
                count=min(count,r-l+1);
                sum=sum-arr[l];
                l++;
            }
        }
        if(count==n+1){
            return -1;
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends

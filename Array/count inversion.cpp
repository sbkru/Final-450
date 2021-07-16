// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long subinversioncount(long long arr[], long long temp[] ,int l, int r){
        long long invcount=0,mid;
        if(l<r){
            mid=(l+r)/2;
            invcount+=subinversioncount(arr,temp,l,mid);
            invcount+=subinversioncount(arr,temp,mid+1,r);
            invcount+=mergeinversioncount(arr,temp,l,r,mid+1);
        }
        return invcount;
    }
    long long mergeinversioncount(long long arr[], long long temp[], int l, int r, int mid){
        long long i=l,j=mid,invcount=0,k=l;
        while(i<=mid-1 && j<=r){
            if(arr[i]>arr[j]){
                temp[k++]=arr[j++];
                invcount+=mid-i;
            }
            else{
                temp[k++]=arr[i++];
            }
        }
        while(i<=mid-1){
            temp[k++]=arr[i++];
        }
        while(j<=r){
            temp[k++]=arr[j++];
        }
        for(i=l;i<=r;i++){
            arr[i]=temp[i];
        }
        return invcount;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long temp[N];
        return subinversioncount(arr,temp,0,N-1);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> s;
        int count=0,j;
        for(int i=0;i<N;i++){
            s.insert(arr[i]);
        }
        for(int i=0;i<N;i++){
            if(s.find(arr[i]-1)==s.end()){
                j=arr[i];
                while(s.find(j)!=s.end()){
                    j++;
                }
                count=max(count,j-arr[i]);
            }
        }
        return count;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends

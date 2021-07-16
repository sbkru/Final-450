// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int i=0;
        int low=0,high=n-1;
        while(high>=i){
            switch(a[i]){
                case 0:
                    swap(a[low++],a[i++]);
                    break;
                 
                case 1: 
                    i++;
                    break;
                
                case 2: 
                    swap(a[i],a[high--]);
                    break;
            }
        } 
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        int mini=prices[0],diff;
        int maxprofit1[n],maxprofit2[n];
        maxprofit1[0]=0;
        for(int i=1;i<n;i++){
            if(mini<prices[i]){
                diff=prices[i]-mini;
            }
            else{
                diff=0;
            }
            maxprofit1[i]=max(maxprofit1[i-1],diff);
            mini=min(mini,prices[i]);
        }
        maxprofit2[n-1]=0;
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(maxi>prices[i]){
                diff=maxi-prices[i];
            }
            else{
                diff=0;
            }
            maxprofit2[i]=max(maxprofit2[i+1],diff);
            maxi=max(maxi,prices[i]);
        }
        int maxprof=maxprofit1[n-1];
        for(int i=1;i<n;i++){
            maxprof=max(maxprof,maxprofit1[i-1]+maxprofit2[i]);
        }
        return maxprof;
    }
};

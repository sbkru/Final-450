class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        int mini=prices[0],diff;
        int maxprofit[n];
        maxprofit[0]=0;
        for(int i=1;i<n;i++){
            if(mini<prices[i]){
                diff=prices[i]-mini;
            }
            else{
                diff=0;
            }
            maxprofit[i]=max(maxprofit[i-1],diff);
            mini=min(mini,prices[i]);
        }
        return maxprofit[n-1];
    }
};

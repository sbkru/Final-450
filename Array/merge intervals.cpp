class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int i=1,j=0;
        vector<vector<int>> v;
        v.push_back(intervals[0]);
        while(i<n){
            if(v[j][1]>=intervals[i][1]){
                i++;
            }
            else if(v[j][1]>=intervals[i][0]){
                v[j][1]=intervals[i][1];
                i++;
            }
            else{
                v.push_back(intervals[i]);
                j++;
                i++;
            } 
        }
        return v;
    }
};

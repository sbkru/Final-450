class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        int ans=0;
        for(int i=0;i<len;i++){
            if(nums[abs(nums[i])]<0){
                ans=abs(nums[i]);
                break;
            }
            else{
                nums[abs(nums[i])]=-1*nums[abs(nums[i])];
            }
        }
        return ans;
    }
};

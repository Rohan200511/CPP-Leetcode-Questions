class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int totalsum;
        for(int num : nums){
            totalsum+=num;
        }
        int leftsum=0;
        for(int i=0;i<nums.size();i++){
            if(leftsum==totalsum-leftsum-nums[i]) return i;
            else leftsum+=nums[i];
        }
        return -1;
    }
};
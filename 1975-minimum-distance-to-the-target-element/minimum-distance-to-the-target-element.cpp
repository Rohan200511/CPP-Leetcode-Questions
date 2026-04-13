class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int index = -1;
        int temp = INT_MAX;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == target && temp > abs(i - start)){
                temp = abs(i - start);
                index = i;
            }
        }
        return temp;
    }
};
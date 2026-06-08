class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>ans;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] < pivot){
                ans.push_back(nums[i]);
            }
        }

        for(int x : nums){
            if(x == pivot) ans.push_back(x);
        }

        for(int y : nums){
            if(y > pivot) ans.push_back(y);
        }

        return ans;
    }
};
class Solution {
public:

    void recurse(vector<int>& nums , int n , vector<vector<int>>& ans , int idx){
        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i = idx ; i < n ; i++){
            swap(nums[i] , nums[idx]);
            recurse(nums,n,ans,idx+1);
            swap(nums[i] , nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        
        recurse(nums , n , ans , 0);
        return ans;
    }
};
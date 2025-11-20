class Solution {
public:
    void recurse(vector<int>& nums , int n , vector<vector<int>>& ans , int idx){
        if(idx == n){
            ans.push_back(nums);
            return;
        }
        unordered_set<int>st;

        for(int i = idx ; i < n ; i++){
            if(st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[idx] , nums[i]);
            recurse(nums,n,ans,idx+1);
            swap(nums[idx] , nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        recurse(nums,n,ans,0);
        return ans;
    }
};
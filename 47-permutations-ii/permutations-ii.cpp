class Solution {
public:
   void getPermutations(vector<int> &nums,int indx,vector<vector<int>> &ans){
        if(indx == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> seen;
        for(int i = indx ; i< nums.size();i++){
            if(seen.count(nums[i])) continue;
            seen.insert(nums[i]);
            swap(nums[indx] , nums[i]);
            getPermutations(nums,indx+1,ans);
            swap(nums[indx]  ,nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        getPermutations(nums,0,ans);
        return ans;
    }
};
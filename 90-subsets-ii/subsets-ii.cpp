class Solution {
public:

    void generateSubsets(vector<int>& nums , vector<vector<int>>& ans ,vector<int>& curr , int i){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        generateSubsets(nums,ans,curr,i+1);

        curr.pop_back();

        int indx = i+1;
        while(indx < nums.size() && nums[indx] == nums[indx-1]) indx++;
        generateSubsets(nums,ans,curr,indx);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int>curr;
        generateSubsets(nums,ans,curr,0);
        return ans;
    }
};
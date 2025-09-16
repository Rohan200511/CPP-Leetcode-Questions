class Solution {
public:

    void generateSubsets(vector<int>& nums , vector<vector<int>>& ans , vector<int>& current , int index){
        if(index == nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        generateSubsets(nums,ans,current,index+1);

        current.pop_back();
        generateSubsets(nums,ans,current,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        generateSubsets(nums,ans,curr,0);
        return ans;
    }
};
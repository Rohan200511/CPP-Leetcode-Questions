class Solution {
public:

    void recurse(vector<int>& nums , int n , vector<int>& curr , vector<vector<int>>& ans , int index){
        if(index == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        recurse(nums , n , curr , ans , index+1);
        curr.pop_back();
        recurse(nums , n , curr , ans , index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        vector<int>curr;

        recurse(nums , n , curr, ans ,0);
        return ans;
    }
};
class Solution {
public:

    vector<vector<int>>ans;
    int n;

    void solve(vector<int>& nums , vector<int>& curr , int i){
        if(i == n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(nums , curr , i + 1);
        curr.pop_back();
        solve(nums , curr , i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int>curr;
        solve(nums , curr , 0);
        return ans;
    }
};
class Solution {
public:

    void helper(vector<int>& candidates , int n , vector<int>& ans,vector<vector<int>>& res,int target,int index){
        if(target == 0){
            res.push_back(ans);
            return;
        }
        if(index==n ||target < 0) return;
        ans.push_back(candidates[index]);
        helper(candidates,n,ans,res,target-candidates[index] , index);
        ans.pop_back();
        helper(candidates,n,ans,res,target,index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int>ans;
        helper(candidates,n,ans,res,target,0);
        return res;
    }
};
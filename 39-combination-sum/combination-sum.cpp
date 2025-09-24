class Solution {
public:

    void helper(vector<int>& candidates, int n, int target , int index , vector<int>& ans,vector<vector<int>>& res){
        if(target == 0){
            res.push_back(ans);
            return;
        }

        if(index == n || target < 0) return ;
        
        ans.push_back(candidates[index]);
        helper(candidates,n,target-candidates[index],index,ans,res);
        ans.pop_back();
        helper(candidates,n,target,index+1,ans,res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>ans;
        vector<vector<int>>res;
        helper(candidates,n,target,0,ans,res);
        return res;
    }
};
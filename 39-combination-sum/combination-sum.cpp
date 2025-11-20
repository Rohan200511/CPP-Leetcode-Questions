class Solution {
public:

    void recurse(vector<int>& candidates , int n , int target , vector<int>& curr , vector<vector<int>>& ans , int idx){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        if(target < 0 || idx == n) return;

        curr.push_back(candidates[idx]);
        recurse(candidates , n , target - candidates[idx] , curr , ans , idx);
        curr.pop_back();
        recurse(candidates , n , target , curr , ans , idx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int>curr;

        recurse(candidates , n , target , curr , ans , 0);
        return ans;
    }
};
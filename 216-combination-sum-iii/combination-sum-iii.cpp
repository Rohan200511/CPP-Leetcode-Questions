class Solution {
public:

    
    void recurse(int k , int n , vector<vector<int>>& ans , vector<int>& curr , int start){
        if(k == 0 && n == 0){
            ans.push_back(curr);
            return;
        }
        if(k == 0 || n <= 0) return;
        for(int i = start ; i <= 9 ; i++){
            curr.push_back(i);
            recurse(k - 1 , n - i , ans , curr , i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        if(k < 0 || n < 0) return {};
        vector<vector<int>>ans;
        vector<int>curr;
        recurse(k , n , ans , curr , 1);
        return ans;
    }
};
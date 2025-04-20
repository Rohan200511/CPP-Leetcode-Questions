class Solution {
public:
   void recurse(int k, int n, int start, vector<vector<int>>& ans, vector<int>& curr){
    if(curr.size()==k &&n==0) {
        ans.push_back(curr);
        return;
    }
    if(curr.size()>k || n<0) return;

    for(int i=start;i<=9;i++){
        curr.push_back(i);
        recurse(k,n-i,i+1,ans,curr);
        curr.pop_back();
    }
   }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> curr;
        recurse(k,n,1,ans,curr);
        return ans;
    }
};
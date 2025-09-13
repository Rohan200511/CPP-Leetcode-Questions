class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>ans;
        for (vector<int>& a : mat) {
             for (int num : a) {
                ans.push_back(num);
             }
        }
        sort(ans.begin(), ans.end());
        return ans[ans.size() / 2];
    }
};

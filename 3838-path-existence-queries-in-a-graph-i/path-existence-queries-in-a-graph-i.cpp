class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<int>root(n , 0);
        int temp = 0;

        for(int i = 1 ; i < n ; i++){
            if(abs(nums[i] - nums[i - 1]) > maxDiff) temp++;

            root[i] = temp;
        }

        vector<bool>ans;

        for(auto& q : queries){
            int u = q[0];
            int v = q[1];

            if(root[u] == root[v]) ans.push_back(true);

            else ans.push_back(false); 
        }
        return ans;
    }
};
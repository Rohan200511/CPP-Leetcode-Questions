class Solution {
public:

    int ans = 0;

    int dfs(unordered_map<int , vector<int>>& adj , string& s , int u){
        int left = 0 , right = 0;

        for(int v : adj[u]){
            int len = dfs(adj , s , v);
            
            if(s[u] == s[v]) continue;

            if(len > left){
                right = left;
                left = len;
            }
            else if(len > right) right = len;
        }

        ans = max(ans , left + right + 1);

        return left + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();

        unordered_map<int , vector<int>>adj(n);

        for(int i = 0 ; i < n ; i++){
            adj[parent[i]].push_back(i);
        }

        dfs(adj , s , 0);

        return ans;
    }
};
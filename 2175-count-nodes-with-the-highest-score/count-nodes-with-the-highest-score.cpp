class Solution {
public:

    int dfs(int u , vector<int>& subtree , unordered_map<int , vector<int>>& adj){
        subtree[u] = 1;

        for(int v : adj[u]){
            subtree[u] += dfs(v , subtree , adj);
        }
        return subtree[u];
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();

        unordered_map<int , vector<int>>adj(n + 1);

        for(int i = 0 ; i < n ; i++){
            adj[parents[i]].push_back(i);
        }

        vector<int>subtree(n , 0);

        dfs(0 , subtree , adj);

        long long maxi = 1;
        int ans = 0;
        
        for(int i = 0 ; i < n ; i++){
            long long score = 1;

            for(int v : adj[i]){
                score *= subtree[v];
            }

            if(n - subtree[i] > 0) score *= (n - subtree[i]);

            if(score > maxi){
                maxi = score;
                ans = 1;
            }
            else if(score == maxi) ans++;
        }
        return ans;
    }
};
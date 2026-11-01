class Solution {
public:

    int dfs1(int u , unordered_map<int , vector<int>>& adj , vector<int>& subtree , vector<bool>& vis){
        subtree[u] = 1;
        vis[u] = true;

        for(int v : adj[u]){
            if(!vis[v]){
                subtree[u] += dfs1(v , adj , subtree , vis);
            }
        }

        return subtree[u];
    }

    void dfs2(unordered_map<int ,vector<int>>& adj , int u , vector<bool>& vis , vector<int>& ans , int depth){
        
        vis[u] = true;
        ans[0] += depth;

        for(int v : adj[u]){
            if(!vis[v]){
                dfs2(adj , v , vis , ans , depth + 1);
            }
        }
    }

    void dfs3(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis, vector<int>& subtree, vector<int>& ans, int n){

        vis[u] = true;

        for(int v : adj[u]){
            if(!vis[v]){
                ans[v] = ans[u] - subtree[v] + (n - subtree[v]);
                dfs3(adj , v , vis , subtree , ans , n);
            }
        }

    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int>subtree(n) , ans(n , 0);

        vector<bool>vis(n , false);
        dfs1(0 , adj , subtree , vis);

        vis.assign(n , false);
        dfs2(adj , 0 , vis , ans , 0);
        
        vis.assign(n , false);
        dfs3(adj , 0 , vis, subtree , ans , n);

        return ans;
    }
};
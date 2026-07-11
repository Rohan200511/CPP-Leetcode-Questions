class Solution {
public:

    int n;
    unordered_map<int , vector<int>>adj;
    vector<bool>vis;

    void dfs(int src , int& nodes , int& edges){
        vis[src] = true;
        nodes++;
        edges += adj[src].size();

        for(auto& v : adj[src]){
            if(!vis[v]){
                dfs(v , nodes , edges);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.reserve(n);
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vis.assign(n , false);

        for(int vertex = 0 ; vertex < n ; vertex++){
            if(!vis[vertex]){
                int nodes = 0;
                int edges = 0;

                dfs(vertex , nodes , edges);
            

                int actualEdges = edges / 2;

                if(actualEdges == (nodes * (nodes - 1) / 2)) ans++;
            }
        }

        return ans;
    }
};
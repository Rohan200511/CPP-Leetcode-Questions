class Solution {
  public:
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        
        for(auto& it : edges){
            int u = it[0];
            int v = it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int farthest = -1;
        int diameter = 0;
        vector<bool>vis(V,false);
        queue<int>q;
        
        q.push(0);
        vis[0] = true;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int v = q.front();
                q.pop();
                farthest = v;

                for (int nei : adj[v]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        
        vis.assign(V, false);
        
        q.push(farthest);
        vis[farthest] = true;
        
        while (!q.empty()) {
            int size = q.size();
            diameter++;   // FIX 3: count levels, not nodes

            for (int i = 0; i < size; i++) {
                int v = q.front();
                q.pop();

                for (int nei : adj[v]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }
        
        return diameter - 1;
    }
};

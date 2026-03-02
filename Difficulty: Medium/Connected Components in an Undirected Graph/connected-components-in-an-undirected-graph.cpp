class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> visited(V, 0);
        vector<vector<int>> components;
    
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> component;
                queue<int> q;
    
                q.push(i);
                visited[i] = 1;
    
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    component.push_back(node);
    
                    for (int nei : adj[node]) {
                        if (!visited[nei]) {
                            visited[nei] = 1;
                            q.push(nei);
                        }
                    }
                }
    
                components.push_back(component);
            }
        }
    
        return components;
    }
};

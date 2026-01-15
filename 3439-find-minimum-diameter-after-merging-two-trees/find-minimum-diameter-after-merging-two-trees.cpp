class Solution {
public:

    int diameter(vector<vector<int>>& adj) {

        if (adj.empty()) return 0;

        int n = adj.size();
        vector<bool> vis(n, false);
        queue<int> q;

       
        q.push(0);
        vis[0] = true;

        int farthest = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
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

        fill(vis.begin(), vis.end(), false);
        while (!q.empty()) q.pop();

        q.push(farthest);
        vis[farthest] = true;

        int diameter = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int v = q.front();
                q.pop();

                for (int nei : adj[v]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
            if (!q.empty()) diameter++;
        }

        return diameter;
    }

    vector<vector<int>> buildAdj(vector<vector<int>>& edges) {

        int n = edges.size() + 1; 
        vector<vector<int>> adj(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {

        if (edges1.empty() && edges2.empty()) return 1;

        vector<vector<int>> adj1 = buildAdj(edges1);
        vector<vector<int>> adj2 = buildAdj(edges2);

        int d1 = diameter(adj1);
        int d2 = diameter(adj2);

        int combined = ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1;

        return max({d1, d2, combined});
    }
};

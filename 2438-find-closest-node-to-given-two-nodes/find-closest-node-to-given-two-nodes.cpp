class Solution {
public:

    void dfs(vector<int>& edges, vector<int>& dist, int u) {

        int v = edges[u];

        if (v == -1) return;

        if (dist[v] != -1) return;

        dist[v] = dist[u] + 1;

        dfs(edges, dist, v);
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {

        int n = edges.size();

        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);

        dist1[node1] = 0;
        dist2[node2] = 0;

        dfs(edges, dist1, node1);
        dfs(edges, dist2, node2);

        int idx = -1;
        int maxMin = INT_MAX;

        for (int i = 0; i < n; i++) {

            if (dist1[i] == -1 || dist2[i] == -1)
                continue;

            int maxi = max(dist1[i], dist2[i]);

            if (maxi < maxMin) {
                maxMin = maxi;
                idx = i;
            }
        }

        return idx;
    }
};
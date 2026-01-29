class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = 4e18;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; i++) dist[i][i] = 0;

        int m = original.size();
        for (int i = 0; i < m; i++) {
            int a = original[i] - 'a';
            int b = changed[i] - 'a';
            dist[a][b] = min(dist[a][b], (long long)cost[i]);
        }

        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        long long ans = 0;
        int n = source.size();
        for (int i = 0; i < n; i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';
            if (dist[s][t] >= INF) return -1;
            ans += dist[s][t];
        }

        return ans;
    }
};
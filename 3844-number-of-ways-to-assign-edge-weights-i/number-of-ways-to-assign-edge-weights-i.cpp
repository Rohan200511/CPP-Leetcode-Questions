class Solution {
public:
    #define MOD 1000000007; 

    int dfs(vector<vector<int>>& adj , int u , int par){
        int depth = 0;

        for(auto& v : adj[u]){
            if(v == par) continue;

            depth = max(depth , dfs(adj , v , u) + 1);
        }
        return depth;
    }

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % MOD;
            }

            a = (a * a) % MOD;
            b /= 2;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size(); 

        vector<vector<int>>adj(n+2);

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = dfs(adj , 1 , 0);
        return modPow(2 , ans - 1);
    }
};
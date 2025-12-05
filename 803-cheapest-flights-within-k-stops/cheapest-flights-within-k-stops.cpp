class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto& e : flights){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v , w});
        }

        vector<int>dist(n , INT_MAX);

        queue<pair<int,int>>q;

        q.push({0 , src});
        dist[src] = 0;

        int stops = 0;

        while(q.size() && stops <= k){
            int N = q.size();
            while(N--){
                auto p = q.front();
                q.pop();
                int d = p.first;
                int node = p.second;

                for(auto& v : adj[node]){
                    int neigh = v.first;
                    int dis = v.second;

                    if(dis + d < dist[neigh]){
                        dist[neigh] = dis + d;
                        q.push({dis+d , neigh});
                    }
                }
            }
            stops++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
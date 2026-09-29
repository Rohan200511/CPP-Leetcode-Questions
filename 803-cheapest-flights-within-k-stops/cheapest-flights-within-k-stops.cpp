class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int , vector<pair<int , int>>>adj(n);

        for(auto& f : flights){
            int u = f[0];
            int v = f[1];
            int p = f[2];

            adj[u].push_back({v , p});
        }

        int stops = 0;

        queue<pair<int , int>>q;
        q.push({0 , src});

        vector<int>minP(n , 1e9);
        minP[src] = 0;

        while(!q.empty() && stops <= k){
            int n = q.size();

            while(n--){
                int cost = q.front().first;
                int u = q.front().second;
                q.pop();

                for(auto& it : adj[u]){
                    int v = it.first;
                    int p = it.second;

                    if(minP[v] > cost + p){
                        minP[v] = cost + p;
                        q.push({cost + p , v});
                    }
                }
            }
            stops++;
        }
        return minP[dst] == 1e9 ? -1 : minP[dst];
    }
};
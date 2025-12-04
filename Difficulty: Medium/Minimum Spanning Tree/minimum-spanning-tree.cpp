class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); 
        }

        
        vector<bool>vis(V , false);
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        pq.push({0 , 0});
        
        int sum = 0;
        
        while(pq.size()){
            auto p = pq.top();
            pq.pop();
            
            int wt = p.first;
            int node = p.second;
            
            if(vis[node]) continue;
            
            vis[node] = true;
            sum += wt;
            
            for(auto e : adj[node]){
                auto neigh = e.first;
                auto weight = e.second;
                if(!vis[neigh])
                    pq.push({weight , neigh});
            }
        }
        
        return sum;
    }
};
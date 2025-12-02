class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v , w});
            adj[v].push_back({u , w});
        }
        
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
        vector<int>ans(V , INT_MAX);
        
        ans[src] = 0;
        pq.push({0 , src});
        
        while(pq.size()){
            auto [d , node] = pq.top();
            pq.pop();
            
            if(d > ans[node]) continue;
            
            for(auto& neigh : adj[node]){
                int dist = neigh.second;
                int vertex = neigh.first;
                
                if(d + dist < ans[vertex]){
                    ans[vertex] = d + dist;
                    pq.push({d + dist , vertex});
                }
            }
        }
         return ans;
    }
};
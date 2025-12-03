// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>result(V , 1e8);
        result[src] = 0;
        
        for(int i = 1 ; i <= V-1 ; i++){
            
            for(auto& e : edges){
                int u = e[0];
                int v = e[1];
                int wt = e[2];
                
                if(result[u] != 1e8 && result[u] + wt < result[v]){
                    result[v] = result[u] + wt;
                }
            }
        }
        
        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            
            if(result[u] != 1e8 && result[u] + wt < result[v]){
                return {-1};
            }
        }
        
        return result;
    }
};

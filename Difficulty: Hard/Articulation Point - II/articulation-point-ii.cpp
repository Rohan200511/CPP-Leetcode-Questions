class Solution {
  public:
    
    vector<int>vis , disc , low;
    int timer = 0;
    
    void tarjan(int u , vector<vector<int>>& adj , int parent , vector<bool>& isArt){
        vis[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;
        
        for(int v : adj[u]){
            
            if(v == parent) continue;
            
            if(!vis[v]){
                children++;
                tarjan(v , adj , u , isArt);
                low[u] = min(low[u] , low[v]);
                
                if(parent != -1 && low[v] >= disc[u]) isArt[u] = true;
            }
            
            //backedge
            if(v != parent) low[u] = min(low[u] , disc[v]);
            
        }
        if(parent == -1 && children > 1) isArt[u] = true;
    }
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>Adj(V);
        
        for(auto& it : edges){
            int u = it[0];
            int v = it[1];
            
            Adj[u].push_back(v);
            Adj[v].push_back(u);
        }
        
        vis.assign(V , false);
        disc.assign(V , 0);
        low.assign(V , 0);
        
        vector<bool>isArt(V , false);
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]) tarjan(i , Adj , -1 , isArt);
        }
        
        vector<int>res;
        
        for(int i = 0 ; i < V ; i++){
            if(isArt[i] == true) res.push_back(i);
        }
        
        if(res.empty()) return {-1};
        
        return res;
    }
};
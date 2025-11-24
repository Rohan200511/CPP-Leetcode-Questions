class Solution {
  public:
    
    void dfs(int src , vector<bool>& vis , int n , int m , vector<vector<int>>& edges , vector<int>& curr){
        vis[src] = 1;
        curr.push_back(src);
        
        for(int i = 0 ; i < edges.size() ; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            if (u == src && !vis[v]) {
                dfs(v , vis , n , m , edges , curr);
            }
            else if (v == src && !vis[u]) {
                dfs(u , vis , n , m , edges , curr);
            }
        }
    }
    
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>ans;
        
        
        int n = edges.size();
        int m = edges[0].size();
        
        vector<bool>vis(V , false);
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                vector<int>curr;
                dfs(i , vis , n , m , edges , curr);
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

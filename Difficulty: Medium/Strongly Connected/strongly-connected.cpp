//Position this line where user code will be pasted.
class Solution {
  public:
     
    void dfsOrder(int u , vector<vector<int>> &adj , vector<bool>& vis , stack<int>& st){
        vis[u] = true;
        
        for(auto& v : adj[u]){
            if(!vis[v]) dfsOrder(v , adj , vis , st);
        }
        
        st.push(u);
    }
    
    void dfs(int u , vector<vector<int>> &revAdj , vector<bool>& vis){
        vis[u] = true;
        
        for(auto& v : revAdj[u]){
            if(!vis[v]) dfs(v , revAdj , vis);
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        
        stack<int>st;
        
        vector<bool>vis(V , false);
        
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]) dfsOrder(i , adj , vis , st);
        }
        
        vector<vector<int>> revAdj(V);
        
        for(int u = 0 ; u < V ; u++){
            for(auto& v : adj[u]){
                revAdj[v].push_back(u);
            }
        }
        
        vis.assign(V , false);
        int count = 0;
        
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            
            if(!vis[node]){
                dfs(node , revAdj , vis);
                count++;
            } 
        }
        
        return count;
    }
};
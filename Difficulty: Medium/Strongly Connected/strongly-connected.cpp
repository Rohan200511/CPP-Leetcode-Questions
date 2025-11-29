//Position this line where user code will be pasted.
class Solution {
  public:
  
    void dfsFill(int u , vector<vector<int>> &adj , stack<int>& st , vector<bool>& visited){
        visited[u] = true;
        
        for(int v : adj[u]){
            if(!visited[v]){
                dfsFill(v , adj , st , visited);
            }
        }
        st.push(u);
    }
    
    
    void dfs(int u , vector<vector<int>>& revAdj , vector<bool>& visited){
        visited[u] = true;
        
        for(int v : revAdj[u]){
            if(!visited[v]){
                dfs(v , revAdj , visited);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        
        stack<int>st;
        vector<bool>visited(V , false);
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                dfsFill(i , adj , st , visited);
            }
        }
        
        vector<vector<int>> revAdj(V);
        
        for(int i = 0 ; i < V ; i++){
            for(int v : adj[i]){
                revAdj[v].push_back(i);
            }
        }
        
         
        int components = 0;
        
        visited.assign(V , false);
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                dfs(node , revAdj , visited);
                components++;
            }
        }
        return components;
    }
};
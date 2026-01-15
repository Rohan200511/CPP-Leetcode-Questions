class Solution {
  public:
    
    void DFS(vector<int> adj[] , int u , vector<bool>& visited){
        visited[u] = true;
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                DFS(adj, v, visited);
            }
        }
    }
    
    bool isConnected(int V, vector<int> adj[]){
        int nonZerovertex = -1;
        
        for(int i = 0 ; i < V ; i++){
            if(adj[i].size() != 0) nonZerovertex = i;
        }
        
        vector<bool>visited(V , false);
        
        DFS(adj , nonZerovertex , visited);
        
        for(int i = 0 ; i < V ; i++){
            if(adj[i].size() !=0 && visited[i] == false) return false;
        }
        return true;
    }
        
    int isEulerCircuit(int V, vector<int> adj[]) {
        
        if(isConnected(V , adj) == false) return 0;
        // Code here
        int oddCount = 0;
        
        for(int i = 0 ; i < V ; i++){
            if(adj[i].size() % 2 != 0) oddCount++;
        }
        
        if(oddCount > 2) return 0;
        else if(oddCount == 2) return 1;
        return 2;
    }
};
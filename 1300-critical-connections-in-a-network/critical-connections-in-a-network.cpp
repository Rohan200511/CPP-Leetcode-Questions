class Solution {
public:

    int timer = 1;

    void dfs(int u , int par , vector<vector<int>>& adj , vector<int>& In , vector<int>& low , vector<bool>& vis , vector<vector<int>>& ans){

        vis[u] = true;
        In[u] = low[u] = timer;
        timer++;

        for(auto v : adj[u]){
            if(v == par) continue;

            if(!vis[v]){
                dfs(v , u , adj , In , low , vis , ans);
                low[u] = min(low[u] , low[v]);

                if(low[v] > In[u]) ans.push_back({u , v});
            }

            else{
                low[u] = min(low[u] , In[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>> adj(n);
        vector<bool>vis(n , false);
        vector<int>In(n);
        vector<int>low(n);
        vector<vector<int>>ans;

        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0 ; i < n ; i++){
            if(!vis[i])
                dfs(i , -1 , adj , In , low , vis , ans);
        }
        return ans;
    }
};
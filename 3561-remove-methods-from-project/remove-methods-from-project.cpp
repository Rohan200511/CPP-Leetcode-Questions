class Solution {
public:

    void dfs(int u , unordered_map<int , vector<int>>& adj , vector<bool>& vis){
        vis[u] = true;

        for(auto& v : adj[u]){
            if(!vis[v]) dfs(v , adj , vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int , vector<int>>adj(n);

        for(auto& e : invocations){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
        }

        vector<bool>vis(n , false);

        dfs(k , adj , vis);

        vector<int>temp;
        bool invoked = false;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                for(auto& v : adj[i]){
                    if(vis[v]){
                        invoked = true;
                        break;
                    }
                }
                temp.push_back(i);
            }
        }

        vector<int>res;

        if(invoked){
            for(int i = 0 ; i < n ; i++) res.push_back(i);
        }

        return (invoked == true) ? res : temp;

    }
};
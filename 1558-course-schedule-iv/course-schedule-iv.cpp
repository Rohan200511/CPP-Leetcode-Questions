class Solution {
public: 

    bool dfs(int src , int dest , vector<bool>& vis , unordered_map<int , vector<int>>& adj){
        vis[src] = true;

        if(src == dest) return true;
        
        for(auto& v : adj[src]){
            if(!vis[v]){
                if(dfs(v , dest , vis , adj)) return true;
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int , vector<int>>adj;

        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool>res(Q);
        
        for(int i = 0 ; i < Q ; i++){
            vector<bool>vis(numCourses , false);
            int u = queries[i][0];
            int v = queries[i][1];

            res[i] = dfs(u , v , vis , adj);
        }
        return res;
    }
};
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses , 0);

        for(auto& it : prerequisites){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);

            indegree[v]++;
        }

        vector<bool>res(queries.size() , false);
        queue<int>q;

        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        unordered_map<int , unordered_set<int>>mp;

        while(q.size()){
            int node = q.front();
            q.pop();

            for(auto& v : adj[node]){
                mp[v].insert(node);

                for(auto& pre : mp[node]){
                    mp[v].insert(pre);
                }

                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        for(int i = 0 ; i < queries.size() ; i++){
            int src = queries[i][0];
            int dest = queries[i][1];

            bool isReachable = mp[dest].contains(src);

            res[i] = isReachable;
        }
        return res;
    }
};
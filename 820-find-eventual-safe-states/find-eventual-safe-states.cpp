class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>rev(n);
        vector<int>indegree(n+1 , 0);

        for(int u = 0 ; u < n ; u++){
            for(auto& v : graph[u]){
                rev[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int>q;
        vector<int>ans;

        for(int i = 0 ; i < n ; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(q.size()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);

            for(auto& it : rev[curr]){
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(ans.begin() , ans.end());
        return ans;
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<pair<int , int>>>adj;

        for(auto& road : roads){
            adj[road[0]].push_back({road[1] , road[2]});
            adj[road[1]].push_back({road[0] , road[2]});
        }

        int ans = 1e5;
        vector<bool>vis(n+1 , false);

        queue<int>q;
        q.push(1);
        vis[1] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(auto& [v , w] : adj[u]){
                ans = min(ans , w);
                
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
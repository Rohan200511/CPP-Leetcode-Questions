class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto& e : times){
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v , t});
        }
        vector<int>time(n+1 , INT_MAX);
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;

        pq.push({0 , k});
        time[k] = 0;

        while(pq.size()){
            auto [tme , node] = pq.top();
            pq.pop();

            for(auto& neigh : adj[node]){
                int t = neigh.second;
                int adjNode = neigh.first;

                if(t + tme < time[adjNode]){
                    time[adjNode] = t + tme;
                    pq.push({t + tme , adjNode});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if(time[i] == INT_MAX) return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int , vector<pair<int , int>>>adj(n);

        for(auto& t : times){
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v , w});
        }

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;

        pq.push({0 , k});

        vector<int>time(n + 1 , INT_MAX);
        time[k] = 0;

        
        while(!pq.empty()){
            int t = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(t > time[u]) continue;

            for(auto& it : adj[u]){
                int v = it.first;
                int w = it.second;

                if(time[v] > t + w){
                    time[v] = t + w;
                    pq.push({t + w , v});
                }
            }
        }

        int ans = -1;

        for(int i = 1 ; i <= n ; i++){
            ans = max(ans , time[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
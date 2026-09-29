class Solution {
public:

    using T = tuple<int , int , int>;

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        unordered_map<int , vector<pair<int , int>>>adj(n + 1);

        for(auto& e : edges){
            int u = e[0];
            int v = e[1];
            int t = e[2];

            adj[u].push_back({v , t});
            adj[v].push_back({u , t});
        }

        priority_queue<T , vector<T> , greater<T>>pq;
        pq.push({passingFees[0] , 0 , 0});

        vector<int>minTime(n , 1e9);
        minTime[0] = 0;

        while(!pq.empty()){
            auto [cost , u , currT] = pq.top();
            pq.pop();

            if(u == n - 1) return cost;

            for(auto& it : adj[u]){
                int v = it.first;
                int T = it.second;

                if(T + currT > maxTime) continue;

                if(minTime[v] > T + currT){
                    minTime[v] = T + currT;
                    pq.push({cost + passingFees[v] , v , T + currT});
                }
            }
        }
        return -1;
    }
};
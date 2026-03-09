class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> graph(n);

        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            graph[u].push_back({v, t});
            graph[v].push_back({u, t});
        }

        vector<int> minTime(n, INT_MAX);
        minTime[0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({passingFees[0], 0, 0}); 

        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int cost = cur[0], city = cur[1], timer = cur[2];

            if (city == n - 1) return cost;

            for (auto& p : graph[city]) {
                int nxtCity = p.first;
                int nxtTime = timer + p.second;

                if (nxtTime > maxTime) continue;

                if (nxtTime >= minTime[nxtCity]) continue;


                minTime[nxtCity] = nxtTime;

                pq.push({cost + passingFees[nxtCity], nxtCity, nxtTime});
            }
        }
        return -1;
    }
};
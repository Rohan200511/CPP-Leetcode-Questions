class Solution {
public:
                
    typedef pair<int , int>P;

    bool check(int mid, unordered_map<int , vector<vector<int>>>& adj , long long k , int n){
        vector<long long>dist(n , LLONG_MAX);

        priority_queue<P , vector<P> , greater<P>>pq;

        dist[0] = 0;
        pq.push({0 , 0});

        while(!pq.empty()){
            long long curr_cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(curr_cost > k) return false;

            if(node == n - 1) return true;

            if(dist[node] < curr_cost) continue;

            for(auto& nei : adj[node]){
                int adjNode = nei[0];
                int cost = nei[1];

                if(cost < mid) continue;

                if(curr_cost + cost < dist[adjNode]){
                    dist[adjNode] = curr_cost + cost;
                    pq.push({curr_cost + cost , adjNode});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        unordered_map<int , vector<vector<int>>>adj;

        int l = INT_MAX , r = 0;

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];

            if(!online[u] || !online[v]) continue;

            adj[u].push_back({v , cost});
            l = min(l , cost);
            r = max(r , cost);
        }

        int ans = -1;

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(check(mid, adj, k, n)){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return ans;
    }
};
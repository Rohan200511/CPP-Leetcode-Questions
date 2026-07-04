class Solution {
public:

    vector<int>parent , rank;
    
    int find(int u){
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }

    void unite(int u , int v){
        int uP = find(u);
        int vP = find(v);

        if (uP == vP) return;

        if(rank[uP] < rank[vP]){
            parent[uP] = vP; 
        }
        else if(rank[uP] > rank[vP]) parent[vP] = uP;

        else{
            rank[uP]++;
            parent[vP] = uP;
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        parent.resize(n+1);
        rank.resize(n+1 , 0);

        for(int i = 0 ; i <= n ; i++) parent[i] = i;

        for(auto& r : roads){
            unite(r[0] , r[1]);
        }

        int source = find(1);

        int ans = 1e5;

        for (auto &road : roads) {
            if (find(road[0]) == source)
                ans = min(ans, road[2]);
        }
        return ans;
    }
};
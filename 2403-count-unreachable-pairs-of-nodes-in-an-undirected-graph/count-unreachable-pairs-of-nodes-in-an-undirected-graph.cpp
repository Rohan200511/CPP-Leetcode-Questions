class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x , int y){
        int xP = find(x);
        int yP = find(y);

        if(xP == yP) return;
        if(rank[xP] > rank[yP]) parent[yP] = xP;
        else if(rank[xP] < rank[yP]) parent[xP] = yP;
        else{
            parent[yP] = xP;
            rank[xP]++;
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.assign(n , 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        for(auto& it : edges){
            int u = it[0];
            int v = it[1];

            unite(u , v);
        }

        unordered_map<int, int>mp;

        for(int i = 0 ; i < n ; i++){
            int par = find(i);
            mp[par]++;
        }
        long long ans = 0;
        long long rem = n;

        for(auto& x : mp){
            long long size = x.second;

            ans += (size) * (rem - size);
            rem -= size;
        }
        return ans;
    }
};
class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv) return true;

        if(rank[pu] > rank[pv]) parent[pv] = pu;
        else if(rank[pu] < rank[pv]) parent[pu] = pv;
        else{
            parent[pv] = pu;
            rank[pu]++;
        }
        return false;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1, 0);
        vector<int> e1, e2;

        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(par[v] == 0) par[v] = u;
            else{
                e1 = {par[v], v};
                e2 = {u, v};
                e[1] = 0;
            }
        }

        parent.resize(n+1);
        rank.assign(n+1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(auto &e : edges){
            int u = e[0], v = e[1];
            if(v == 0) continue;

            if(unite(u, v)){
                if(e1.empty()) return {u, v};
                return e1;
            }
        }

        return e2;
    }
};
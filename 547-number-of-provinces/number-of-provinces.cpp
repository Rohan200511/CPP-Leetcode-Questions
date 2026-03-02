class Solution {
public: 

    vector<int>rank;
    vector<int>parent;

    void unite(int u , int v){
        int uP = find(u);
        int vP = find(v);

        if(uP == vP) return;

        if(rank[uP] < rank[vP]) parent[uP] = vP;
        else if(rank[uP] > rank[vP]) parent[vP] = uP;
        else {
            parent[vP] = uP;
            rank[uP]++;
        }
    }

    int find(int u){
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rank.assign(n , 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1) unite(i , j);
            }
        }

        for(int i = 0 ; i < n ; i++){
            if(find(i) == i) count++;
        }

       return count;
    }
};
class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int u , int v ){
        int uP = find(u );
        int vP = find(v);

        if(uP == vP)return;
        if(rank[uP] > rank[vP]) parent[vP] = uP;
        else if(rank[uP] < rank[vP]) parent[uP] = vP;
        else{
            parent[uP] = vP;
            rank[vP]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1) return -1 ;

        parent.resize(n);
        rank.resize(n , 0);

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        int components = n;

        for(auto& vec : connections){
            if(find(vec[0]) != find(vec[1])){
                unite(vec[0] , vec[1]);
                components--;
            }
        }
        return components - 1;
    }
};
class Solution {
public:

    vector<int>rank;
    vector<int>parent;

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a , int b){
        int aP = find(a);
        int bP = find(b);

        if(rank[aP] < rank[bP]){
            parent[aP] = bP;
        }
        else if(rank[aP] > rank[bP]){
            parent[bP] = aP;
        }
        else{
            rank[aP]++;
            parent[bP] = aP;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();

        parent.resize(n);
        rank.resize(n , 0);

        for(int i = 0 ; i < n ; i++) parent[i] = i;

        for(auto& it : allowedSwaps){
            int x = it[0];
            int y = it[1];

            unite(x , y);
        }

        unordered_map<int , unordered_map<int,int>>componentsElements;

        for(int i = 0 ; i < n ; i++){
            int curr = source[i];

            int currP = find(i);

            componentsElements[currP][curr]++;
        }

        int hammingDistance = 0;

        for(int i = 0; i < n; i++){
            int currP = find(i);

            if(componentsElements[currP][target[i]] > 0){
                componentsElements[currP][target[i]]--;
            }
            else hammingDistance++;
        }
        return hammingDistance;
    }
};
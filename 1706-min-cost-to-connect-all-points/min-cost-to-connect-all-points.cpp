class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int x){

        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
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
    
    int manhattan(vector<int> p1 , vector<int> p2){
        return (abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]));
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        parent.resize(n);
        rank.assign(n , 0);

        int minCost = 0;

        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }

        vector<vector<int>>edges;

        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1 ; j < n ; j++){

                int d = manhattan(points[i] , points[j]);

                edges.push_back({i , j , d});
            }
        }

        sort(edges.begin() , edges.end() , [&](auto& a , auto& b){
            return a[2] < b[2];
        });

        for(auto& e : edges){
            int a = e[0];
            int b = e[1];
            int dist = e[2];

            if(find(a) != find(b)){
                unite(a , b);
                minCost += dist;
            }
        }
        return minCost;
    }
};
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int minCost = 0 ;

         sort(costs.begin(), costs.end(),
             [](vector<int>& a, vector<int>& b){
                 return (a[0] - a[1]) < (b[0] - b[1]);
             });
        for(int i = 0 ; i < n/2 ; i++){
            minCost += costs[i][0];
        }

        

        for(int i = n/2 ; i < n ; i++){
            minCost += costs[i][1];
        }

        return minCost;
    }
};
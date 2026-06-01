class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin() , cost.end() , greater<int>());

        int ans = 0 , count = 0;

        for(int i = 0 ; i < n ; i++){
            if(count == 2){
                count = 0;
                continue;
            }
            count++;
            ans += cost[i];
        }

        return ans;
    }
};
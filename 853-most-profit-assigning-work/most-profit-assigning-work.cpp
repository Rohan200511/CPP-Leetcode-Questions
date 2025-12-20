class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>temp;

        for(int i = 0 ; i < profit.size() ; i++){
            temp.push_back({difficulty[i] , profit[i]});
        }

        sort(temp.begin() , temp.end());
        sort(worker.begin() , worker.end());
        int totalProfit = 0;

        for(int& work : worker){
            int ans = 0;
            for(int i = 0 ; i < temp.size() ; i++){
                if(work >= temp[i].first) ans = max(ans , temp[i].second);
                else break;
            }
            totalProfit += ans;
        }
        return totalProfit;
    }
};
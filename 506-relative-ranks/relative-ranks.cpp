class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int , int>>pq;
        vector<string>ans(n);
        for(int i = 0 ; i < n ; i++){
            pq.push({score[i] , i});
        }
       int place = 1;
        while(!pq.empty()){
            int rank = pq.top().second;
            pq.pop();
            
            if(place == 1) ans[rank] = "Gold Medal";
            else if(place == 2) ans[rank] = "Silver Medal";
            else if(place == 3) ans[rank] = "Bronze Medal";
            else ans[rank] = to_string(place);
            place++;
        }
        return ans;
    }
};
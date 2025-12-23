class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin() , events.end());
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>>pq;
        int maxVal = 0 , ans = 0;

        for(auto& x : events){
            int srt = x[0];
            int end = x[1];
            int val = x[2];

            while(!pq.empty() && pq.top().first < srt){
                maxVal = max(maxVal , pq.top().second);
                pq.pop();
            }

            ans = max(ans , maxVal + val);

            pq.push({end , val});
        }
        return ans;
    }
};
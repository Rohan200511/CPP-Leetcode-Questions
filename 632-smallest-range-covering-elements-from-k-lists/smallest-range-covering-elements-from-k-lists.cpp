class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> pq;

        int maxEl = INT_MIN;
        vector<int>ans = {-1000000 , 1000000};

        for(int i = 0 ; i < k ; i++){
            pq.push({nums[i][0] , i , 0});
            maxEl = max(maxEl , nums[i][0]);
        }

        while(!pq.empty()){
            vector<int>curr = pq.top();
            pq.pop();

            int minEl = curr[0];
            int listidx = curr[1];
            int idx = curr[2];

            if(maxEl - minEl < ans[1] - ans[0]){
                ans[1] = maxEl;
                ans[0] = minEl;
            }

            if(idx + 1 < nums[listidx].size()){
                int nextEl = nums[listidx][idx+1];
                pq.push({nextEl , listidx , idx+1});
                maxEl = max(nextEl , maxEl);
            }
            else break;
        }
        return ans;
    }
};
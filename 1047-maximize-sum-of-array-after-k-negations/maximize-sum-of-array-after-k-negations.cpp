class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<int,vector<int>,greater<int>>pq;

        for(int i = 0 ; i < n ; i++){
            pq.push(nums[i]);
        }

        while(k--){
            int top = pq.top();
            pq.pop();
            pq.push(top * -1);
        }
        int sum = 0;
        while(pq.size()){
            sum += pq.top();
            pq.pop();
        }
        return sum == 0 ? 0 : sum;
    }
};
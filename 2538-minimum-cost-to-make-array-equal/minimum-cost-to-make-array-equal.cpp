class Solution {
public:

    long long totalCost(vector<int>& nums, vector<int>& cost , int target){
        
        long long costt = 0;

        for(int i = 0 ; i < nums.size() ; i++){
            costt += llabs(nums[i] - target) * cost[i];
        }

        return costt;

    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = *min_element(nums.begin() , nums.end());
        long long right = *max_element(nums.begin() , nums.end());

        long long ans = LLONG_MAX;

        while(left <= right){
            long long mid = left + (right - left) / 2;

            long long cost1 = totalCost(nums , cost , mid);
            long long cost2 = totalCost(nums , cost , mid - 1);

            ans = min({ans , cost1 , cost2});

            if(cost1 < cost2){
                left = mid + 1;
            }
            else right = mid - 1;

        }

        return (ans == LLONG_MAX) ? 0 : ans;
    }
};
class Solution {
public:

    long long int findCost(vector<int>& nums , vector<int>& cost , int tomake){
        long long totalCost = 0;

        for(int i = 0; i < nums.size(); i++){
            totalCost += llabs(tomake - nums[i]) * cost[i];
        }
        return totalCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long low = *min_element(nums.begin() , nums.end());
        long long high = *max_element(nums.begin() , nums.end());
        while(low < high){
            long long mid = low + ((high - low) / 2);

            long long c1 = findCost(nums , cost , mid);
            long long c2 = findCost(nums , cost , mid+1);

            if(c1 < c2) high = mid;
            else low = mid + 1;
        }
        return findCost(nums, cost, low);;
    }
};
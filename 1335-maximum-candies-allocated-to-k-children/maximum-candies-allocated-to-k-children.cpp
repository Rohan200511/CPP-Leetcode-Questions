class Solution {
public: 

    bool check(vector<int>& arr, long long k , int mid){
        
        long long total_child = 0;

        for(int i = 0 ; i < arr.size() ; i++){
            total_child += arr[i] / mid;
        }
        return total_child >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        if(candies.empty()) return 0;
        long long total = accumulate(candies.begin(),candies.end(),0LL);

        if(total < k) return 0;
        int low = 1;
        int high = *max_element(candies.begin(),candies.end());
        int ans = 0;

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(check(candies , k , mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
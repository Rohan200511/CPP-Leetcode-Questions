class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low < high){
            int mid = low + (high - low) / 2;
            
            if(nums[mid] < nums[mid+1]) low = mid+1;
            else high = mid;
        }

        long long asc_sum = 0 , des_sum = 0;

        for(int i = 0 ; i <= low ; i++){
            asc_sum += nums[i];
        }

        for(int i = low ; i < n ; i++) des_sum += nums[i];

        if(asc_sum > des_sum) return 0;
        else if(asc_sum < des_sum) return 1;
        return -1;
    }
};
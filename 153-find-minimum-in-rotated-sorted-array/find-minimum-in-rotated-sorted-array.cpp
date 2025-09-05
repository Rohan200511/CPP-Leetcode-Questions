class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;

        while(lo<=hi){
            int mid = (lo+hi)>>1;

            if(mid!=0 && nums[mid] < nums[mid-1]) return nums[mid];
            else if(hi-lo+1==1) return nums[lo];

            else if(nums[mid] > nums[hi]) lo = mid+1;
            else hi = mid-1;
        }
        return nums[hi-lo+1];
    }
};
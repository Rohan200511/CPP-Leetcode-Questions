class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int beg = 0;
        int end = n - 1;
        int ans = n;

        while(beg<=end){
            int mid = (beg+end)/2;

            if(target == nums[mid]) return mid;

            else if (target < nums[mid]){
                ans = mid;
                end = mid-1;
            }

            else beg = mid+1;
        }
        return ans;
    }
};
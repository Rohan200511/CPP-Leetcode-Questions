class Solution {
public:
    int countPairs(vector<int>& nums, int maxDist) {
        int cnt = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (nums[right] - nums[left] > maxDist)
                left++;
            cnt += right - left;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.back() - nums.front();
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (countPairs(nums, mid) >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

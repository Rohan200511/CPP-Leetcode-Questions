class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int>arr(2 * limit + 2 , 0);

        for(int i = 0 ; i < n / 2 ; i++){
            int a = nums[i];
            int b = nums[n - i - 1];

            int sum = a + b;

            int low = 1 + min(a , b);
            int high = limit + max(a , b);

            arr[2] += 2;
            arr[low] -= 1;
            arr[high + 1] += 1;

            arr[sum] -= 1;
            arr[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int curr = 0;

        for(int range = 2 ; range <= 2 * limit ; range++){
            curr += arr[range];
            ans = min(ans , curr);
        }
        return ans;
    }
};
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIdx = 0, maxIdx = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int front = max(minIdx, maxIdx) + 1;

        int back = n - min(minIdx, maxIdx);

        int mix1 = minIdx + 1 + (n - maxIdx);

        int mix2 = maxIdx + 1 + (n - minIdx);

        return min({front, back, mix1, mix2});
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        unordered_set<int> need;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target[i]) {
                need.insert(nums[i]);
            }
        }

        return need.size();
    }
};
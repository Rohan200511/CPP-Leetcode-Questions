class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        int sum = 0;
        int count=0;

        for(int i =0;i< nums.size();i++){
            sum+=nums[i];

            if(sum == k) count++;

            if(prefix.find(sum-k)!=prefix.end()) count+=prefix[sum-k];
            prefix[sum]++;
        }
        return count;
    }
};
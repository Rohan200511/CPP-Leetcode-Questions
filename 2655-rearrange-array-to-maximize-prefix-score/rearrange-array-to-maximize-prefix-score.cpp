class Solution {
public:
    int maxScore(vector<int>& nums) {
        int score = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<>());

        vector<long long int>prefix(n+1);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(long long int num : prefix){
            if(num > 0) score++;
        }
        return score;
    }
};
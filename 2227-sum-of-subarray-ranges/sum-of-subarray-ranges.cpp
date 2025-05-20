class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            long long maxi = nums[i];
            long long mini = nums[i];
            for(int j=i;j<n;j++){
                maxi = max(maxi,(long long)nums[j]);       // take care of type casting here
                mini = min(mini,(long long)nums[j]);
                sum += maxi - mini;
            }
        }
        return sum;
    }
};
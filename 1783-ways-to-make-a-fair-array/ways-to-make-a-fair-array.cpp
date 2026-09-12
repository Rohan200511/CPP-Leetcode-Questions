class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int allEven = 0;
        int allOdd = 0;

        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                allEven += nums[i];
            }
            else allOdd += nums[i];
        }

        int leftEven = 0;
        int leftOdd = 0;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                allEven -= nums[i];
            }
            else {
                allOdd -= nums[i];
            }

            int newE = leftEven + allOdd; 
            int newO = leftOdd + allEven;
            
            if(newE == newO) ans++;

            if(i % 2 == 0) leftEven += nums[i];
            else leftOdd += nums[i];
        }

        return ans;
    }
};
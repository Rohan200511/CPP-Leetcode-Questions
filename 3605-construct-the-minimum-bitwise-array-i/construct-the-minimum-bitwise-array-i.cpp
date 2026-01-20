class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , -1);

        for(int i = 0 ; i < n ; i++){
            int x = nums[i];

            for(int j = 0 ; j <= x ; j++){

                int a = j;
                int b = j + 1;

                if((a | b) == x){
                    ans[i] = a;
                    break;
                }
            }
        }
        return ans;
    }
};
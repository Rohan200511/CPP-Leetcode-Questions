class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elesum=0;
        int digitsum=0;
        for(int i : nums){
            elesum+=i;
            while(i>0){
                digitsum+=i%10;
                i/=10;
            }
        }
        return abs(elesum-digitsum);
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        int PosInd=0,NegInd=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                result[NegInd]=nums[i];
                NegInd+=2;
            }
            else{
                result[PosInd]=nums[i];
                PosInd+=2;
            }
        }
        return result;
    }
};
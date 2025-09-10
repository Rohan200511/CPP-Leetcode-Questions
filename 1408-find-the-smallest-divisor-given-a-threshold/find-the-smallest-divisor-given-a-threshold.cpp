class Solution {
public:

    int compute(vector<int>& a , int divisor){
        int n = a.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += (a[i] + divisor - 1) / divisor;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(low<=high){
            int mid = (low+high)>>1;
            if(compute(nums,mid)<=threshold) {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
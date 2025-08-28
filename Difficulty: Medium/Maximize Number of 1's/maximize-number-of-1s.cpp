class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        int left = 0 , maxi = 0, zero=0;
        for(int right = 0;right<arr.size();right++){
            if(arr[right]==0) zero++;
            
            while(zero > k) {
                if(arr[left]==0) zero--;
                left++;
            }
            maxi = max(maxi,right-left+1);
        }
        return maxi;
    }
};

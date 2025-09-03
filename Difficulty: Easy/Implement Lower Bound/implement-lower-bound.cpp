class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int beg = 0;
        int end = n-1;
        int ans = n;
        
        while(beg<=end){
            int mid = beg+(end-beg)/2;
            
            if(arr[mid]>=target){
                ans=mid;
                end = mid-1;
            }
            else beg = mid+1;
        }
        return ans;
    }
};

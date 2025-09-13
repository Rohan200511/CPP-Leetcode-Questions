class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int n , int C , int minAllowdist){
        int cows = 1;
        int lastPos = arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i] - lastPos >= minAllowdist){
                cows ++;
                lastPos = arr[i];
            }
            if(cows == C) return true;
        }
        return false;
    }
  
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int n = stalls.size();
        int low = 1;
        int high = stalls[n-1] - stalls[0];
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            
            if(isPossible(stalls,n,k,mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};
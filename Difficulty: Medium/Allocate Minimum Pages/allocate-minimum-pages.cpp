class Solution {
  public:
  
  
    bool isPossible(vector<int>& arr,int n,int k,int pages){
        int sum = arr[0];
        int nS = 1;
        
        for(int i =1 ;i<n;i++){
            if (arr[i] > pages) return false;
            if(sum + arr[i] <= pages){
                sum += arr[i];
            }
            else{
                nS++;
                sum = arr[i];
            }
            
            if(nS > k) return false;
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int low = *max_element(arr.begin(),arr.end());
        int high = accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        if(n < k) return ans;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1; 
        }
        return ans;
    }
};
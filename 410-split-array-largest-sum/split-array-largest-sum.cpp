class Solution {
public:
    bool isPossible(vector<int>& arr,int n,int k,int maxSum){
        int sum = arr[0];
        int nS = 1;
        
        for(int i =1 ;i<n;i++){
            if (arr[i] > maxSum) return false;
            if(sum + arr[i] <= maxSum){
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

    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        if(n < k) return ans;
        while(low<=high){
            int mid = (low+high)/2;
            
            if(isPossible(nums,n,k,mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1; 
        }
        return ans;
    }
};
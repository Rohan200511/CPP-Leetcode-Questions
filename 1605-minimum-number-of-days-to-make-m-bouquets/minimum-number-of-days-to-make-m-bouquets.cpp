class Solution {
public:
    bool possible(vector<int>& a , int day , int m ,int k){
        int count = 0 ;
        int noB = 0;
        int n = a.size();
        for(int i=0;i<n;i++){
            if(a[i]<=day) count++;
            else {
                noB += count / k;
                count = 0;
            }
        }
        noB += count/k;
        return noB >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,bloomDay[i]);        
            mini = min(mini,bloomDay[i]);        
        }
        int low = mini , high = maxi;
        long long val = m * 1LL* k * 1LL;
        if(val > n) return -1; 
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(bloomDay,mid,m,k)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
};
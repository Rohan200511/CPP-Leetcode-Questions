class Solution {
public:
    int findmax(vector<int> &arr){
        int maxi=arr[0];
        int n=arr.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
    long long findhours(vector<int>& a , int hour){
        long long  totalh=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            totalh+=(a[i] + hour - 1LL) / hour;
        }
        return totalh;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=findmax(piles);
        while(low<=high){
            int mid = low + (high - low) / 2;
            long long totalhours=findhours(piles,mid);
            if(totalhours<=h) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
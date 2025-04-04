class Solution {
public:
    bool possible(vector<int> &a,int day,int m,int k){
        int count=0,noB=0;
        for(int i=0;i<a.size();i++){
            if(a[i]<=day){
                count++;
            }
            else{
                noB+=count/k;
                count=0;
            }
        }
        noB+=count/k;
        return noB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        int n=bloomDay.size();
        if(val>n) return -1;
        int mini=INT_MAX,maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        int low=mini,high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
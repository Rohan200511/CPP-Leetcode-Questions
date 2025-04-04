class Solution {
public:
    int finddays(vector<int> &arr,int days){
        int load=0;
        int day=1;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(load+arr[i] > days){
                day+=1;
                load=arr[i];
            }
            else load+=arr[i];
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int noOfdays=finddays(weights,mid);
            if(noOfdays<=days) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};
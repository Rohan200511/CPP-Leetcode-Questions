class Solution {
public:
    int CountPartitions(vector<int> &a , int maxsum){
        int partitons=1;
        long long sum=0;
        for(int i=0;i<a.size();i++){
            if(sum+a[i]<=maxsum) sum+=a[i];
            else{
                partitons++;
                sum=a[i];
            }
        }
        return partitons;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            int part=CountPartitions(nums,mid);
            if(part>k) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};
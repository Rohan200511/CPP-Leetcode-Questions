class Solution {
public:
    bool noofDays(vector<int>& arr,int mid,int D){
        int days = 1;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]<=mid) sum+=arr[i];
            else{
                days++;
                sum = arr[i];
            }
        }
        return days<=D;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(low<=high){
            int mid = (low+high)/2;

            if(noofDays(weights,mid,days)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
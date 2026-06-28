class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int maxVal = INT_MIN;

        sort(arr.begin() , arr.end());

        if(arr[0] != 1){
            arr[0] = 1;
        }
        maxVal = 1;

        for(int i = 1 ; i < n ; i++){
            if(abs(arr[i] - arr[i-1]) <= 1){
                maxVal = max(maxVal , arr[i]);
                continue;
            }
            else{
                arr[i] = arr[i-1] + 1;
            }
            maxVal = max(maxVal , arr[i]);
        }
        return maxVal;
    }
};
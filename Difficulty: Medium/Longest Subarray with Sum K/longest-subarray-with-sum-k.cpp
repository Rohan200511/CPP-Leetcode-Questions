class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<long long,int> prefix;
        long long sum = 0;
        int maxi = 0;

        for(int i = 0 ; i < arr.size() ; i++){
            sum += arr[i];

            if(sum == k) maxi = max(maxi,i+1);

            if(prefix.find(sum - k) != prefix.end()){
                maxi = max(maxi,i-prefix[sum-k]);
            }

            if(prefix.find(sum) == prefix.end()){
                prefix[sum] = i;
            }
        }
        return maxi;
    }
};
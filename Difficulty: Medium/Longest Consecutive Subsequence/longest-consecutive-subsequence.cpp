class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int sub = 1;
        int maxi =0;
        for(int i = 1;i<arr.size();i++){
            if(arr[i] == arr[i-1]+1) {
                sub++;
            }
            else if(arr[i]!=arr[i-1])sub = 1;
            maxi = max(maxi , sub);
        }
        return maxi;
    }
};
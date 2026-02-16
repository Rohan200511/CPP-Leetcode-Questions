class Solution {
  public:
    vector<vector<int>> missingRanges(vector<int> &arr, int lower, int upper) {
        // Code here
        int n = arr.size();
        
        vector<vector<int>>ans;
        
        if (n == 0) {
            ans.push_back({lower, upper});
            return ans;
        }
        
        if(lower < arr[0]) ans.push_back({lower , arr[0] - 1});
        
        for(int i = 0 ; i < n-1 ; i++){
            if((arr[i+1]) - (arr[i]) > 1){
                ans.push_back({arr[i] + 1 , arr[i+1] - 1});
            }
        }
        
        if(n > 0 && arr[n-1] < upper) ans.push_back({arr[n-1] + 1 , upper});
        
        return ans;
    }
};

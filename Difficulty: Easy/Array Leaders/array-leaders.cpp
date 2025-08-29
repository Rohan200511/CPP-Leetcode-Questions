

class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int n = arr.size();
      vector<int> ans;
      ans.push_back(arr[n-1]);

      for(int i = n-2 ; i >=0; i--){
        if(arr[i]  >= ans.back()) ans.push_back(arr[i]);
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};
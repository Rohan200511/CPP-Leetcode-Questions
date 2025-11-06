// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        unordered_set<int>st;
        
        for(int i = 0 ; i < arr.size() ; i++){
            
            int diff = target - arr[i];
            
            if(st.find(diff) != st.end()) return true;
            
            st.insert(arr[i]);
        }
        return false;
    }
};
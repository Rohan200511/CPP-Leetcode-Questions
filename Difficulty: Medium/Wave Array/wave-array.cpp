class Solution {
  public:
    void sortInWave(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        for(int i = 0; i < n; i += 2){
            if(i+1 < n && arr[i] < arr[i+1]) swap(arr[i] , arr[i+1]);
        }
    }
};
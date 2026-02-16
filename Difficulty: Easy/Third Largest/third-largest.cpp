class Solution {
  public:
    int thirdLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n < 3) return -1;
        
        int first = INT_MIN , second = INT_MIN , third = INT_MIN;
        
        for(int i = 0 ; i < n ; i++){
            int n = arr.size();
    if (n < 3) return -1;

    sort(arr.begin(), arr.end());
    return arr[n - 3];
        }
        
        
        return third;
    }
};
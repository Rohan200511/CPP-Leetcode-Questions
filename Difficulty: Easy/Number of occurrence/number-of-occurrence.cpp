class Solution {
  public:
  
    int freq(vector<int>& arr , int n , int target, int index = 0){
        if(index == n) return 0; 
        if(arr[index] == target) return 1 + freq(arr , n, target , index+1);
        
        return freq(arr , n ,target , index+1);
    }
    
    int countFreq(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return freq(arr,n,target);
       
    }
};

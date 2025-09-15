class Solution {
  public:
  
   void reverse(vector<int>& arr , int n,int index){
       if(index >= n/2 ) return;
    
       swap(arr[n-index-1] , arr[index]);
       
       reverse(arr,n,index+1);
   }
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        int i = 0;
        reverse(arr,n,i);
    }
};
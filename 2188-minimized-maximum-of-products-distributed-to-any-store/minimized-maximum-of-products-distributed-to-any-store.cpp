class Solution {
public: 

    bool check(int n , vector<int>& arr , int mid){
        int total = 0;
        for(int& a : arr){
            total += (a + mid - 1) / mid;
        }
        return total <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = 1e6;
        int ans = -1;

        while(low < high){
            int mid = low + ((high - low) / 2);

            if(check(n , quantities , mid)){
                ans = mid;
                high = mid;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
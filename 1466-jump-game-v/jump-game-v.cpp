class Solution {
public:

    int n;
    vector<int>t;

    int solve(vector<int>& arr , int i , int d){
    
        if(t[i] != -1) return t[i];

        int ans = 1;

        for(int j = i - 1 ; j >= 0 && j >= i - d ; j--){
            if(arr[j] >= arr[i]) break;

            ans = max(ans , 1 + solve(arr , j , d));
        }

        for(int j = i + 1 ; j <= n - 1 && j <= i + d ; j++){
            if(arr[j] >= arr[i]) break;

            ans = max(ans , 1 + solve(arr , j ,d));
        }

        return t[i] = ans;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        t.resize(n + 1 , -1);
        int result = 1;

        for(int i = 0 ; i < n ; i++){
            result = max(result , solve(arr , i , d));
        }

        return result;
    }
};
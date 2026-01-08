class Solution {
public:
    int n , m;
    vector<vector<int>>dp;
    vector<int>a , b;

    int memo(int i , int j){
        if(i == n || j == m) return -1e9;

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int pickup = a[i] * b[j];

        int res = max({pickup + memo(i+1 , j+1),
                        pickup,
                        memo(i+1 , j),
                        memo(i , j+1)
                    });

        return dp[i][j] = res;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        a = nums1 , b = nums2;
        n = nums1.size();
        m = nums2.size();

        dp.assign(n , vector<int>(m , INT_MIN));
        return memo(0 , 0);
    }
};
class Solution {
public:
    int n;
    vector<vector<vector<int>>>t;

    int solve(int i , int k , int hold , vector<int>& prices){
        if(i == n || k == 0) return 0;

        if(t[i][k][hold] != -1) return t[i][k][hold];

        int ans;

        if(hold == 0){
            ans = max(solve(i + 1 , k , hold , prices) , 
                        -prices[i] + solve(i + 1 , k , 1 , prices));
        }

        if(hold == 1){
            ans = max(solve(i + 1 , k , hold , prices) , 
                        prices[i] + solve(i + 1 , k - 1 , 0 , prices));
        }
        return t[i][k][hold] = ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        t.assign(n + 1 , vector<vector<int>>(k + 1 , vector<int>(2 , -1)));              
        return solve(0 , k , 0 , prices);
    }
};
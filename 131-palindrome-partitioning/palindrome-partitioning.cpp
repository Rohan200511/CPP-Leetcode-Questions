class Solution {
public:

    void solve(int i , const string& s , vector<string>& curr , vector<vector<string>>& ans ,vector<vector<bool>>& t){
        if(i == s.length()){
            ans.push_back(curr);
            return;
        }

        for(int j = i ; j < s.length() ; j++){
            if(t[i][j] == true){
                curr.push_back(s.substr(i , j - i + 1));
                solve(j+1 , s , curr , ans , t);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();

        vector<vector<bool>>t(n , vector<bool>(n , false));

        for(int i = 0 ; i < n ; i++) t[i][i] = true;

        for(int L = 2 ; L <= n ;  L++){
            for(int i = 0 ; i + L - 1 < n ; i++){
                int j = i + L - 1;

                if(L == 2 && s[i] == s[j]) t[i][j] = true;

                else{
                    if(s[i] == s[j] && t[i+1][j-1]) t[i][j] = true;
                }
            }
        }

        vector<vector<string>>ans;
        vector<string>curr;

        solve(0 , s , curr , ans , t);

        return ans;
    }
};
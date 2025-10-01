class Solution {
public:

    void solve(string &s , int n , int ind , vector<string>& ans){
        if(ind == n){
            ans.push_back(s);
            return;
        }

        if(isalpha(s[ind])){
            s[ind] = tolower(s[ind]);
            solve(s,n,ind+1,ans);
            s[ind] = toupper(s[ind]);
            solve(s,n,ind+1,ans);
        }
        else solve(s,n,ind+1,ans);
    }

    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        vector<string>ans;
        solve(s,n,0,ans);
        return ans;
    }
};
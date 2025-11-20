class Solution {
public:

    void recurse(int open , int close , vector<string>& ans , string curr){
        if(open == 0 && close == 0){
            ans.push_back(curr);
            return;
        }

        if(open > 0) recurse(open - 1 , close , ans , curr + "(");
        if(close > open) recurse(open , close - 1 , ans , curr + ")");

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string curr;
        recurse(n , n , ans , curr);
        return ans;
    }
};
class Solution {
public:

    void recurse(string digits , int n , vector<string>& ans , string& curr , string mp[] , int idx){
        if(idx == n){
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for(char c : letters){
            curr += c;
            recurse(digits,n,ans,curr,mp,idx+1);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};
        int n = digits.length();
        vector<string>ans;
        string mp[10] = {" " , " " , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        string curr;
        recurse(digits , n , ans , curr , mp , 0);
        return ans;
    }
};
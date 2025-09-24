class Solution {
public:

    void lc(const string &digits,int index,string mp[],vector<string>& res,string &ans){
        if(index == digits.size()){
            res.push_back(ans);
            return;
        }

        string letters = mp[digits[index]-'0'];
        for(char c : letters){
            ans+=c;
            lc(digits,index+1,mp,res,ans);
            ans.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string mp[10] = {" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        string ans;
        lc(digits,0,mp,res,ans);
        return res;
    }
};
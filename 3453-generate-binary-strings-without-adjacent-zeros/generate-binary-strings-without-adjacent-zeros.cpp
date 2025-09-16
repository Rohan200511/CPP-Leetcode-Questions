class Solution {
public:

    void genStr(int n , vector<string>& res , string curr){
        if(n == 0){
            res.push_back(curr);
            return;
        }
        
        genStr(n - 1 ,res , curr + '1');
        if(curr.empty() || curr.back()!='0') genStr(n - 1 , res , curr+'0');
    }

    vector<string> validStrings(int n) {
        vector<string>res;
        genStr(n , res, "");
        return res;
    }
};
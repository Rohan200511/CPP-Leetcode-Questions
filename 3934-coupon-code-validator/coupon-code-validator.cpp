class Solution {
public:

    bool isValidCode(const string& s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!isalnum(c) && c != '_') return false;
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<pair<string,string>> v;

        for(int i = 0 ; i < businessLine.size() ; i++){
            if(!isActive[i]) continue;
            if(code[i] == "" || !isValidCode(code[i])) continue;

            if(businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant"){
                v.push_back({businessLine[i], code[i]});
            }
        }
        sort(v.begin(), v.end()); 
        vector<string> ans;
        for(auto &p : v){
                ans.push_back(p.second);
        }
        return ans;
    }
};
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();

        set<string>st;

        for(int i = 0 ; i + k <= n ; i++){
            string temp = s.substr(i , k);
            st.insert(temp);
        }

        if(st.size() == pow(2 , k)) return true;
        return false;
    }
};
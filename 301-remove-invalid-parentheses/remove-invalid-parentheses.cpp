class Solution {
public:
    int n;
    unordered_set<string> st;

    bool valid(string &s) {
        int cnt = 0;

        for(char c : s) {
            if(c == '(') cnt++;
            else if(c == ')') cnt--;

            if(cnt < 0) return false;
        }

        return cnt == 0;
    }

    void removeParantheses(string &ans, string &s, int idx) {
        if(idx == s.length()) {
            if(ans.length() == n && valid(ans)) {
                st.insert(ans);
            }
            return;
        }

        if(s[idx] == '(' || s[idx] == ')') {
            removeParantheses(ans, s, idx + 1);
        }

        ans.push_back(s[idx]);
        removeParantheses(ans, s, idx + 1);
        ans.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        int res = 0;
        int cnt = 0;

        for(char c : s) {
            if(c == '(') cnt++;
            else if(c == ')') cnt--;

            if(cnt < 0) {
                res++;
                cnt++;
            }
        }

        n = s.length() - (res + abs(cnt));

        string ans = "";
        removeParantheses(ans, s, 0);

        vector<string> result(st.begin(), st.end());
        return result;
    }
};
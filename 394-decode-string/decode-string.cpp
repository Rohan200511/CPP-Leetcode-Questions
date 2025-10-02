class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (char c : s) {
            if (c != ']') {
                st.push(string(1, c));
            } 
            else {
                string curr = "";
                while (!st.empty() && st.top() != "[") {
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop();

                string numStr = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    numStr = st.top() + numStr;
                    st.pop();
                }
                int num = stoi(numStr);
                
                string temp = "";
                for (int i = 0; i < num; i++) temp += curr;
                st.push(temp);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
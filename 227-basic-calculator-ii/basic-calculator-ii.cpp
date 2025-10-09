class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long long int num = 0;
        char op = '+';

        for(int i = 0 ; i < s.length() ; i++){
            char c = s[i];
            
            if(isdigit(c)) num = (num * 10) + (c - '0');

            if((!isdigit(c) && !isspace(c)) || i == s.length() - 1){
                if(op == '+') st.push(num);

                else if(op == '-') st.push(-num);

                else if(op == '*'){
                    int top = st.top();  st.pop();
                    st.push(top * num);
                }

                else if(op == '/'){
                    int top = st.top() ;  st.pop();
                    st.push(top / num);
                }
                op = c;
                num = 0;
            }
        }
        int ans = 0;

        while(!st.empty()){
                ans += st.top();
                st.pop();
        }
        return ans;
    }
};
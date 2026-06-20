class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.length();
        stack<char>st;

        for(char c : expression){
            if(c == ',' || c == '(') continue;

            if(c == 'f' || c == 't' || c == '|' || c == '&' || c == '!') st.push(c);

            else if(c == ')'){
                bool hasT = false , hasF = false;

                while(st.top() != '&' && st.top() != '!' && st.top() != '|'){
                    char exp = st.top();
                    st.pop();

                    if(exp == 't') hasT = true;
                    if(exp == 'f') hasF = true;
                }
                char op = st.top();
                st.pop();

                if(op == '!'){
                    if(hasF) st.push('t');
                    else st.push('f');
                }

                else if(op == '&'){
                    if(hasF) st.push('f');

                    else st.push('t');
                }
                else if(op == '|'){
                    if(hasT) st.push('t');
                    else st.push('f');
                }
            }
        }
        return st.top() == 't';
    }
};
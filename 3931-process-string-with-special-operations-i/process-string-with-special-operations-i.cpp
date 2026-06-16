class Solution {
public:
    string processStr(string str) {
        string s;

        for(char c : str){
            if(c == '#'){
                s += s;
            }
            else if(c == '*'){
                if(s.length()) s.pop_back();
            }
            else if(c == '%') reverse(s.begin() , s.end());

            else s += c;
        }

        return s;
    }
};
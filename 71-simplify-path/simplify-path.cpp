class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        stack<string> st;

        for(int i = 0; i < n; i++) {
            string dir = "";
            while(i < n && path[i] != '/') {
                dir += path[i];
                i++;
            }
            if(dir == "" || dir == ".") continue;
            else if(dir == "..") {
                if(!st.empty()) st.pop();
            } 
            else st.push(dir);
        }
        vector<string> dirs;
        while(!st.empty()) {
            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());
        string res = "";
        for(auto &d : dirs) res += "/" + d;

        return res.empty() ? "/" : res;
    }
};
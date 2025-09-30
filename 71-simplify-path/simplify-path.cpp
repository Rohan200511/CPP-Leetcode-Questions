class Solution {
public:
    string simplifyPath(string path) {
        int n = path.length();
        vector<string> v;

        for(int i = 0 ; i < n ; i++){
            string dir = "";

            while(i < n && path[i] != '/'){
                dir += path[i];
                i++;
            }
            if(dir == ".."){
                if(!v.empty())
                    v.pop_back();
            }
            else if(dir == "" || dir == ".") continue;
            else v.push_back(dir);

        }

        string res = "";

        for(auto it : v){
            res += "/" + it;
        }
        
        if (res == "")
        return "/";

        return res;
    }
};
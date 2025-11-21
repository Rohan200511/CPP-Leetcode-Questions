class Solution {
public:
    int n;
    vector<string>result;

    bool isValid(string st){
        if(st[0] == '0') return false;

        int val = stoi(st);
        if(val > 255) return false;

        return true;
    }

    void recurse(string s , int parts , string curr , int idx){
        if(idx == n && parts == 4){
            curr.pop_back();
            result.push_back(curr);
            return;
        }

        if(idx + 1 <= n)
            recurse(s , parts + 1 , curr + s.substr(idx , 1) + '.' , idx + 1);
        
        if(idx + 2 <= n && isValid(s.substr(idx , 2)))    
            recurse(s , parts + 1 , curr + s.substr(idx , 2) + '.' , idx + 2);
        
        if(idx + 3 <= n && isValid(s.substr(idx , 3)))
            recurse(s , parts + 1 , curr + s.substr(idx , 3) + '.' , idx + 3);
    }


    vector<string> restoreIpAddresses(string s) {
        n = s.length();
        if(n > 12) return {};
        int parts = 0;
        string curr = "";

        recurse(s , parts , curr , 0);

        return result;
    }
};
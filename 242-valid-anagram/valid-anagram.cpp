class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length() , m = t.length();

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        return s == t;
    }
};
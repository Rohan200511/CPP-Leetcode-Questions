class Solution {
public:

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        int Len = 1;
        int Start = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int len = j - i + 1;

                if (len > Len && isPalindrome(s, i, j)) {
                    Len = len;
                    Start = i;
                }
            }
        }

        return s.substr(Start, Len);
    }
};
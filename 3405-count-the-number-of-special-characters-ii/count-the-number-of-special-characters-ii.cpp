class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> lastLower;
        unordered_map<char, int> firstUpper;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (islower(ch)) {
                lastLower[ch] = i;   
            } 
            else {
                if (!firstUpper.count(ch)) {
                    firstUpper[ch] = i; 
                }
            }
        }

        int ans = 0;

        for (auto &[c, idx] : lastLower) {
            char up = toupper(c);

            if (firstUpper.count(up) && idx < firstUpper[up]) {
                ans++;
            }
        }

        return ans;
    }
};
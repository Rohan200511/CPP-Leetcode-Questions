class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string s;
        for (auto &c : chunks) s += c;

        unordered_map<string,int> freq;
        int n = s.size();

        auto isLower = [&](char c) {
            return c >= 'a' && c <= 'z';
        };

        int i = 0;

        while (i < n) {
            if (!isLower(s[i])) {
                i++;
                continue;
            }

            int j = i;
            string w;

            while (j < n) {
                if (isLower(s[j])) {
                    w += s[j];
                } 
                else if (s[j] == '-' && j - 1 >= i &&j + 1 < n && isLower(s[j - 1]) && isLower(s[j + 1])) {
                w += s[j];
                } 
                else {
                    break;
                }
                j++;
            }

            freq[w]++;
            i = j;
        }

        vector<int> ans;

        for (auto &q : queries)
            ans.push_back(freq[q]);

        return ans;
    }
};
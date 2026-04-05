class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char , int>freq;

        int sum = 0;

        for(char c : s){
            freq[c]++;
        }

        for(char c : s){
            if(freq[c] == -1) continue;

            char mirror;

            if(isdigit(c)) mirror = '9' - (c - '0');

            else mirror = 'z' - (c - 'a');

            sum += abs(freq[c] - freq[mirror]);

            freq[c] = freq[mirror] = -1;
        }
        return sum;
    }
};
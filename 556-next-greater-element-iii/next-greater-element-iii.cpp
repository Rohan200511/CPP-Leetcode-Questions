class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (!next_permutation(s.begin(), s.end()))
            return -1;
        long long val = stoll(s);
        return (val > INT_MAX) ? -1 : (int)val;
    }
};
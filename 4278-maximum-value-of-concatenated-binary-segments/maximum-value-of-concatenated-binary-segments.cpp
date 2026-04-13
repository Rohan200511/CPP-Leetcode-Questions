class Solution {
public:

    int MOD = 1e9 + 7;
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<string> segs;
        for (int i = 0; i < nums1.size(); i++) {
            segs.push_back(string(nums1[i], '1') + string(nums0[i], '0'));
        }

        sort(segs.begin(), segs.end(), [](const string &A, const string &B){
            return A + B > B + A;
        });

        long long val = 0;
        for (auto &s : segs) {
            for (char c : s) {
                val = (val * 2 + (c - '0')) % MOD;
            }
        }
        return (int)val;

    }
};
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,vector<int>> pos;
        for(int i = 0; i<n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<long long> res (n,0);
        
        for(auto &it : pos) {
            vector<int> &v = it.second;
            int m = v.size();

            long long pref_sum = 0;
            long long suff_sum = 0;

            for(long long i = 0; i<m; i++) {
                pref_sum += v[i];
                res[v[i]] += v[i] * i - pref_sum;
                suff_sum += v[m-i-1];
                res[v[m-i-1]] += suff_sum - (v[m-i-1] * i);
            }
        }

        return res;
    }
};
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,int>mp;

        for (int x : nums) {
            if (x < 1 || x > n - 1)
                return false;

            mp[x]++;
        }

        for(int i = 1 ; i <= n - 2 ; i++){
            if(mp[i] != 1) return false;
        }

        return mp[n - 1] == 2;
    }
};
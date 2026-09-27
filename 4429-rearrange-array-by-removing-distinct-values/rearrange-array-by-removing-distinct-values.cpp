class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> mp;
        
        for (int x : nums)
            mp[x]++;
        
        vector<int> ans;
        
        while (!mp.empty()) {
            vector<int> remove;
            
            for (auto &[x, freq] : mp) {
                ans.push_back(x);
                freq--;
                
                if (freq == 0)
                    remove.push_back(x);
            }
            
            for (int x : remove)
                mp.erase(x);
        }
        
        return ans;
    }
};
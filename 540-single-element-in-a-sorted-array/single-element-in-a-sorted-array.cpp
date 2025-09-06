class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;

        for(int num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            if(it.second==1) return it.first;
        }
        return -1;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int , int>freq;

        for(int num : nums) freq[num]++;

        for(auto& it : freq){
            if(it.second > (n / 2)) return it.first;
        }
        return -1;
    }
};
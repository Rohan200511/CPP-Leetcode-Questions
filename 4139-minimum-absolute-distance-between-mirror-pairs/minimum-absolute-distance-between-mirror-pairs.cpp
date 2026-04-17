class Solution {
private:
    int reverse(int n) {
        int rev = 0;
        while (n != 0) {
            int digit = n % 10;     
            rev = rev * 10 + digit; 
            n /= 10;               
        }
        return rev;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int dist = INT_MAX;
        unordered_map<int,int>mp;

        for(int i = 0 ; i < n ; i++){
            int rev_num = reverse(nums[i]);

            if(mp.find(nums[i]) != mp.end()){
                dist = min(dist , abs(i - mp[nums[i]]));
            }
            mp[rev_num] = i;
        }

        if(dist == INT_MAX) return -1;
        return dist;
    }
};
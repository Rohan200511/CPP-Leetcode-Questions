class Solution {
public:

    int findAns(int i , vector<int>& nums , int k , int x){
        vector<int>temp;
        for(int j = i ; j < i+k ; j++){
            temp.push_back(nums[j]);
        }
        unordered_map<int,int>mp;
        for(auto& it : temp) mp[it]++;

        vector<pair<int, int>> freq;
        for (auto& [num, count] : mp) {
            freq.push_back({count, num});
        }

        sort(freq.begin(), freq.end(), [](auto& a, auto& b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        });

        int sum = 0;
        int cnt = 0;

        for (auto& [count, num] : freq) {
            if(cnt == x) break;
            sum += count * num;
            cnt++;
        }

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int>ans(n-k+1);

        for(int i = 0 ; i < (n-k+1) ; i++){
            ans[i] = findAns(i,nums,k,x);
        }
        return ans;
    }
};
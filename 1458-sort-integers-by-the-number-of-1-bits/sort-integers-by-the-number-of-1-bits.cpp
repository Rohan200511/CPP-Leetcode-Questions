class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>ans;

        for(auto& num : arr){
            ans.push_back({__builtin_popcount(num) , num});
        }
        sort(ans.begin(),ans.end());

        vector<int>temp;
        for(auto& it : ans){
            temp.push_back(it.second);
        }
        return temp;
    }
};
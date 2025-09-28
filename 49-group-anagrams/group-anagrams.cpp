class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;

        for(auto x : strs){
            string word = x;
            sort(word.begin(),word.end());
            mp[word].push_back(x);
        }

        vector<vector<string>>ans;
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
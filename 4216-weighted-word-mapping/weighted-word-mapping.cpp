class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        map<string, int>mp;

        for(auto& it : words){
            string word = it;
            int weight = 0;
            for(int i = 0 ; i < word.length() ; i++){
                weight += weights[word[i] - 'a'];
            }
            mp[word] = weight % 26;
        }
        string ans = "";
        for(auto& word : words){
            ans += ('z' - mp[word]);
        }
        return ans;
    }
};
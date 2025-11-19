class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]  = i;
        }

        vector<int>result;
        int start = 0 , end = 0;

        for(int i = 0 ; i < s.length() ; i++){
            end = max(end , mp[s[i]]);

            if(i == end){
                result.push_back(end - start + 1);
                start = i+1;
            }
        }
        return result;
    }
};
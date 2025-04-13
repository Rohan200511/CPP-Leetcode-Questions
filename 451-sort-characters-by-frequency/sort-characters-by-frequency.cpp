 bool compare(pair<char,int>&a , pair<char,int>&b){
        return a.second > b.second;
    }
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        vector<pair<char,int>>freqvec(freq.begin(),freq.end());
        sort(freqvec.begin(),freqvec.end(),compare);

        string ans="";
        for(auto &it : freqvec){
            ans+=string(it.second,it.first);
        }
        return ans;
    }
};
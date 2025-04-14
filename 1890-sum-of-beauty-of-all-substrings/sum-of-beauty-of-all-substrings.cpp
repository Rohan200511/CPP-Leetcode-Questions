class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int total=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;

                int max_freq=0;
                int min_freq=INT_MAX;

                for(auto &it : freq){
                    max_freq=max(it.second,max_freq);
                    min_freq=min(it.second,min_freq);
                }
                total+=(max_freq-min_freq);
            }
        }
        return total;
    }
};
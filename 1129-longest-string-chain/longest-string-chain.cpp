class Solution {
public:

    int t[1001][1001];

    bool isPred(string a , string b){
        if(b.length() - a.length() != 1) return false;

        int i = 0 , j = 0;

        while(i < a.length() && j < b.length()){
            if(a[i] == b[j]) i++;
            j++;
        }

        return i == a.length();
    }

    int solve(vector<string>& words , int curr , int prev){
        if(curr == words.size()) return 0;

        if(prev != -1 && t[curr][prev] != -1) return t[curr][prev];

        int take = 0;
        if(prev == -1 || isPred(words[prev] , words[curr])){
            take = 1 + solve(words , curr + 1 , curr);
        }

        int skip = solve(words , curr+1 , prev);

        if(prev != -1){
            t[curr][prev] = max(take , skip);
        }

        return max(take , skip);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin() , words.end() , [](auto& a , auto& b){
            return a.length() < b.length();
        });

        memset(t , -1 , sizeof(t));

        return solve(words , 0 , -1);
    }
};
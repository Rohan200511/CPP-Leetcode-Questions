class Solution {
public:

    int n , m;

    vector<vector<int>>t;

    int solve(const string& s1 , const string& s2 , int i , int j){
        if(i == n) return m - j;
        else if(j == m) return n - i;

        if(t[i][j] != -1) return t[i][j];

        if(s1[i] == s2[j]) return t[i][j] = solve(s1 , s2 , i + 1 , j + 1);

        int insert = 1 + solve(s1 , s2 , i , j + 1);
        int del =  1 + solve(s1 , s2 , i + 1 , j);
        int replace = 1 + solve(s1 , s2 , i + 1 , j + 1);

        return t[i][j] = min({insert , del , replace});
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();

        t.assign(n + 1 , vector<int>(m + 1 , -1));

        return solve(word1 , word2 , 0 , 0);
    }
};
class Solution {
public:

    int m , n;
    vector<vector<int>>t;

    int solve(string& word1 , string& word2 , int i , int j){
        if(i == m) return n - j;
        else if( j == n) return m - i;

        if(t[i][j] != -1) return t[i][j];

        if(word1[i] == word2[j]) return solve(word1 , word2 , i + 1 , j + 1);

        int insert = 1 + solve(word1 , word2 , i , j + 1);
        int deletee = 1 + solve(word1 , word2 , i + 1 , j) ;
        int replace = 1 + solve(word1 , word2 , i + 1 , j + 1);

        return t[i][j] = min({insert , deletee , replace});
    }

    int minDistance(string word1, string word2) {
        m = word1.length();
        n = word2.length();
        t.assign(m + 1 , vector<int>(n + 1 , -1));
        return solve(word1 , word2 , 0 , 0);
    }
};
class Solution {
public:
    int t[501][501];
    int solve(string s1 , string s2 , int n , int m , int i , int j){
        if(i == n) return m-j;
        else if(j == m) return n-i;
        if(t[i][j] != -1) return t[i][j];
        if(s1[i] == s2[j]) return t[i][j] = solve(s1,s2,n,m,i+1,j+1);
        int insert = 1 + solve(s1,s2,n,m,i,j+1);
        int del = 1 + solve(s1,s2,n,m,i+1,j);
        int replace = 1 + solve(s1,s2,n,m,i+1,j+1);

        return t[i][j] = min({insert , del , replace});
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        memset(t,-1,sizeof(t));
        return solve(word1,word2,n,m,0,0);
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>cnt1(n+1 , 0) , cnt2(n+1 , 0);

        for(int i = 0 ; i < trust.size() ; i++){
            cnt1[trust[i][0]]++;
            cnt2[trust[i][1]]++;
        }

        for(int i = 1 ; i <= n ; i++){
            if(cnt1[i] == 0 && cnt2[i] == n-1) return i;
        }
        return -1;
    }
};
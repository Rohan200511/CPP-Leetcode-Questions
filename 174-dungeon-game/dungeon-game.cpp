class Solution {
public:
    int m , n;
    vector<vector<int>>t;
    int solve(int i , int j , vector<vector<int>>& dungeon){
        if(i >= m || j >= n) return INT_MAX;

        if(t[i][j] != -1) return t[i][j];

        if(i == m-1 && j == n-1){
            return (dungeon[i][j] > 0) ? 1 : abs(dungeon[i][j]) + 1;
        }

        int right = solve(i , j + 1 , dungeon);
        int down = solve(i + 1 , j , dungeon);

        int result = min(right , down) - dungeon[i][j];
        
        return t[i][j] = (result > 0) ? result : 1 ;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();
        t.assign(m , vector<int>(n , -1));
        return solve(0 , 0 , dungeon);
    }
};
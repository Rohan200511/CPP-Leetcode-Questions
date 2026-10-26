class Solution {
public:

    int n , m;

    long long solve(int i , int j , vector<vector<int>>& grid){
        if(i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0) return 0;
        
        long long sum = grid[i][j];

        grid[i][j] = 0;

        sum += solve(i , j - 1 , grid); 
        sum += solve(i , j + 1 , grid);
        sum += solve(i - 1 , j , grid);
        sum += solve(i + 1, j, grid);

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 0 && solve(i , j , grid) % k == 0){
                    count++;
                }
            }
        }

        return count;
    }
};
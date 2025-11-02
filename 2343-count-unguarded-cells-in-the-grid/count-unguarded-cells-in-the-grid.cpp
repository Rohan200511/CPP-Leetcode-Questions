class Solution {
public:

    void markGuarded(int m , int n , int row , int col , vector<vector<int>>& grid){

        for(int i = row - 1 ; i >= 0 ; i--) {
            if(grid[i][col] == 2 || grid[i][col] == 3) break;
            grid[i][col] = 1;
        }
        for(int i = row + 1 ; i < m ; i++) {
            if(grid[i][col] == 2 || grid[i][col] == 3) break;
            grid[i][col] = 1;
        }
        for(int i = col - 1 ; i >= 0 ; i--) {
            if(grid[row][i] == 2 || grid[row][i] == 3) break;
            grid[row][i] = 1;
        }
        for(int i = col + 1 ; i < n ; i++) {
            if(grid[row][i] == 2 || grid[row][i] == 3) break;
            grid[row][i] = 1;
        }

    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m , vector<int>(n , 0));

        for(vector<int>& vec : guards){
            int i = vec[0];
            int j = vec[1];

            grid[i][j] = 2;
        }

        for(vector<int>& vec : walls){
            int i = vec[0];
            int j = vec[1];

            grid[i][j] = 3;
        }

        for(vector<int>& guard : guards){
            int i = guard[0];
            int j = guard[1];
            markGuarded(m,n,i,j,grid);
        }

        int count = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0) count++;
            }
        }
        return count;
    }
};
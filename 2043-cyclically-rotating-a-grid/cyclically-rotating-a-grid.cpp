class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int noofLayers = min(m , n) / 2;

        for(int l = 0 ; l < noofLayers ; l++){
            vector<int>vals;

            int left = l , right = n - l - 1;
            int top = l , bottom = m - l - 1;

            for(int i = left ; i <= right ; i++){
                vals.push_back(grid[top][i]);
            }

            for(int j = top + 1 ; j <= bottom ; j++){
                vals.push_back(grid[j][right]);
            }

            for(int kk = right - 1 ; kk >= left ; kk--){
                vals.push_back(grid[bottom][kk]);
            }

            for(int x = bottom - 1 ; x > top ; x--){
                vals.push_back(grid[x][left]);
            }

            int size = vals.size();
            int rt = k % size;

            rotate(vals.begin() , vals.begin() + rt , vals.end());

            int idx = 0;

            for(int i = left ; i <= right ; i++){
                grid[top][i] = vals[idx++];
            }

            for(int j = top + 1 ; j <= bottom ; j++){
                grid[j][right] = vals[idx++];
            }

            for(int kk = right - 1 ; kk >= left ; kk--){
                grid[bottom][kk] = vals[idx++];
            }

            for(int x = bottom - 1 ; x > top ; x--){
                grid[x][left] = vals[idx++];
            }
        }
        return grid;
    }
};
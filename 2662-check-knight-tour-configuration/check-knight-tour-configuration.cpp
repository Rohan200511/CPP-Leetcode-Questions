class Solution {
public:

    bool isValid(vector<vector<int>>& grid , int n , int r , int c , int expVal){
        if(r<0 || r>=n || c<0 || c>=n || grid[r][c]!=expVal) return false;
        if(expVal == n*n-1) return true;
        bool ans1 = isValid(grid,n,r-2,c+1,expVal+1);
        bool ans2 = isValid(grid,n,r-1,c+2,expVal+1);
        bool ans3 = isValid(grid,n,r+1,c+2,expVal+1);
        bool ans4 = isValid(grid,n,r+2,c+1,expVal+1);
        bool ans5 = isValid(grid,n,r+2,c-1,expVal+1);
        bool ans6 = isValid(grid,n,r+1,c-2,expVal+1);
        bool ans7 = isValid(grid,n,r-1,c-2,expVal+1);
        bool ans8 = isValid(grid,n,r-2,c-1,expVal+1);

        return ans1 ||ans2 ||ans3 ||ans4 ||ans5 ||ans6 ||ans7 ||ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n = grid.size();
        return isValid(grid,n,0,0,0);
    }
};
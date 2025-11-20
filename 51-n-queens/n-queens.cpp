class Solution {
public:

    bool isSafe(vector<string>& board , int n , int row , int col , vector<vector<string>>& ans){
        for(int i = 0 ; i < n ; i++){
            if(board[row][i] == 'Q') return false;
        }

        for(int j = 0 ; j < n ; j++){
            if(board[j][col] == 'Q') return false;
        }

        for(int k = row , l = col ; k >= 0 && l >= 0 ; k-- , l--){
            if(board[k][l] == 'Q') return false;
        }

        for(int m = row , p = col ; m >= 0 && p < n ; m-- , p++){
            if(board[m][p] == 'Q') return false;
        }
        return true;
    }

    void nQueens(int n , vector<string>& board , int row , vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n ; i++){
            if(isSafe(board , n , row , i , ans)){
                board[row][i] = 'Q';
                nQueens(n , board , row+1 , ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n , string(n , '.'));
        vector<vector<string>>ans;
        nQueens(n , board , 0 , ans);
        return ans;
    }
};
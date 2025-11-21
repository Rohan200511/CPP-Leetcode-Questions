class Solution {
public:

    bool isSafe(vector<vector<char>>& board , int row , int col , char digit){
        for(int i = 0 ; i < 9 ; i++){
            if (board[row][i] == digit || board[i][col] == digit) 
                    return false;
        }

        int boxrow = row / 3 * 3;
        int boxcol = col / 3 * 3;

        for(int k = 0 ; k < 3 ; k++){
            for(int l = 0 ; l < 3 ; l++){
                if(board[boxrow + k][boxcol + l] == digit) return false;
            }
        }
        return true;
    }

    bool recurse(vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                if(board[i][j] == '.'){
                    for(char c = '1' ; c <= '9' ; c++){
                        if(isSafe(board , i , j ,c)){
                            board[i][j] = c;
                            if(recurse(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recurse(board);
    }
};
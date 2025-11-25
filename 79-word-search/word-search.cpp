class Solution {
public:

    bool isPossible(vector<vector<char>>& board , string word , int i , int j , int index , int rows , int cols){
        if(index == word.length()) return true;
        if(i < 0 || j < 0 || i >= rows || j >= cols) return false;
        if(board[i][j] != word[index] || board[i][j] == '$') return false;

        char c = board[i][j];
        board[i][j] = '$';

        bool up = isPossible(board , word , i-1 , j ,index+1 , rows , cols);
        bool down = isPossible(board , word , i+1 , j ,index+1 , rows , cols);
        bool left = isPossible(board , word , i , j-1 ,index+1 , rows , cols);
        bool right = isPossible(board , word , i , j+1 ,index+1 , rows , cols);

        board[i][j] = c;
        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[index]){
                    if(isPossible(board , word , i , j , index , n , m)) return true;
                }
            }
        }
        return false;
    }
};
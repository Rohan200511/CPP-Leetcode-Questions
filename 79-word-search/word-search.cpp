class Solution {
public:

    bool isPossible(vector<vector<char>>& board , int n , int m , string word , int idx , int i , int j){
        if(idx == word.length()) return true;
        if(i < 0 || i >= n || j < 0 || j >= m) return false;
        if(board[i][j] != word[idx] || board[i][j] == '$') return false;

        char original = board[i][j];
        board[i][j] = '$';

        bool left = isPossible(board , n , m , word , idx + 1 , i-1 , j);
        bool right = isPossible(board , n , m , word , idx + 1 , i+1 , j);
        bool up = isPossible(board , n , m , word , idx + 1 , i , j-1);
        bool down = isPossible(board , n , m , word , idx + 1 , i , j+1);

        board[i][j] = original;

        return up || right || down || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int idx = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == word[idx]){
                    if(isPossible(board , n , m , word , idx , i , j)) return true;
                }
            }
        }
        return false;
    }
};
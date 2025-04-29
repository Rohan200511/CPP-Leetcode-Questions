class Solution {
public:

    bool recurse(vector<vector<char>> &board, int index,int row,int col, int n, int m, string word){
        if(word.length()==index) return true;
        if(row < 0 || col < 0 || row >= n || col >= m) return false;
        if(board[row][col] != word[index] || board[row][col] == '#') return false;
        char c = board[row][col];
        board[row][col] = '#';

        bool bottom = recurse(board , index+1 , row+1,col,n,m,word);
        bool top  = recurse(board , index+1 , row-1,col,n,m,word);
        bool left =  recurse(board , index+1 , row,col-1,n,m,word);
        bool right =  recurse(board , index+1 , row,col+1,n,m,word);
        
        board[row][col] = c;
        return top || bottom || left || right;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(board[i][j] == word[index]){
                    if(recurse(board, index,i,j, n , m , word)) return true;
                }
            }
        }
            return false;
    }
};
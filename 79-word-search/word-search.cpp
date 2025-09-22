class Solution {
public:

    bool isPossible(vector<vector<char>>& board , string word,int row,int col,int index,int n,int m){
        if(index == word.length()) return true;
        if(row<0 || col<0 || row>=n || col>=m) return false;
        if(board[row][col]!=word[index] || board[row][col] == '$') return false;
        char c = board[row][col];
        board[row][col] = '$';

        bool up = isPossible(board,word,row-1,col,index+1,n,m);
        bool right = isPossible(board,word,row,col+1,index+1,n,m);
        bool down = isPossible(board,word,row+1,col,index+1,n,m);
        bool left = isPossible(board,word,row,col-1,index+1,n,m);

        board[row][col] = c;
        return up || right || down || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int index = 0;
        for(int i = 0;i < n ; i++){
            for(int j = 0;j<m;j++){
                if(board[i][j] == word[index]){
                    if(isPossible(board,word,i,j,index,n,m)) return true;
                }
            }
        }
        return false;
    }
};
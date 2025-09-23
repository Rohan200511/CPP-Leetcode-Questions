class Solution {
public:
    int count = 0;

    bool issafe(vector<string>& board , int n,int row,int col,vector<vector<string>>& ans){
        for(int i = 0;i<n;i++){
            if(board[row][i] == 'Q') return false;
        }

        for(int j = 0;j<n;j++){
            if(board[j][col] == 'Q') return false;
        }

        for(int k = row,l = col ; k>=0 && l>=0 ; k--,l--){
            if(board[k][l] == 'Q') return false;
        }

        for(int k = row,l=col ; k>=0 && l<n; k--,l++){
            if(board[k][l] == 'Q') return false;
        }
        return true;
    }
    
    void nQueens(vector<string>& board,int n, int row,vector<vector<string>>& ans){
        if(row == n){
            count++;
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(issafe(board,n,row,i,ans)){
                board[row][i] = 'Q';
                nQueens(board,n,row+1,ans);
                board[row][i] = '.';
            }
        }
    }

    void NQueens(int n){
        vector<string>board(n,string(n,'.'));
        vector<vector<string>> ans;
        nQueens(board,n,0,ans);
    }

    int totalNQueens(int n) {
        NQueens(n);
        return count;
    }
};
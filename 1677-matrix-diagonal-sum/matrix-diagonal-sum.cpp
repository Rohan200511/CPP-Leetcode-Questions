class Solution {
    private:
    int leftdiagonalsum(vector<vector<int>>& mat){
        int sum=0;
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==j) sum+=mat[i][j];
            }
        }
        return sum;
    }
    int rightdiagonalsum(vector<vector<int>>& mat){
        int sum=0;
        int row=mat.size();
        if(row==0 || mat[0].size()==0) return 0;
        for(int i=0;i<row;i++){
            sum+=mat[i][row-i-1];
        }
        return sum;
    }
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int leftSum = leftdiagonalsum(mat);
        int rightSum = rightdiagonalsum(mat);
        int n = mat.size();
        if (n % 2 != 0) {
            int middle = mat[n / 2][n / 2];
            return leftSum + rightSum - middle;
        }
        return leftSum + rightSum;
    }
};
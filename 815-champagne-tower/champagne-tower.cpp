class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double t[101][101] = {0.0};

        t[0][0] = poured;

        for(int i = 1 ; i <= 100 ; i++){
            for(int j = 0 ; j <= i ; j++){
                double left_up = max(0.0 , (j - 1 >= 0) ? (t[i-1][j-1] - 1.0) / 2.0 : 0.0);
                double right_up = max(0.0 , (j < i) ? (t[i-1][j] - 1.0) / 2.0 : 0.0);

                t[i][j] = ((left_up + right_up) < 0) ? 0.0 : left_up + right_up;
            }
        }
        return min(1.0, t[query_row][query_glass]);
    }
};
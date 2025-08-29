class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int srow = 0, erow = n - 1;
        int scol = 0, ecol = m - 1;

        while (srow <= erow && scol <= ecol) {
            for (int i = scol; i <= ecol; i++) {
                ans.push_back(matrix[srow][i]);
            }
            srow++;

            for (int j = srow; j <= erow; j++) {
                ans.push_back(matrix[j][ecol]);
            }
            ecol--;

            if (srow <= erow) {
                for (int k = ecol; k >= scol; k--) {
                    ans.push_back(matrix[erow][k]);
                }
                erow--;
            }

            if (scol <= ecol) {
                for (int l = erow; l >= srow; l--) {
                    ans.push_back(matrix[l][scol]);
                }
                scol++;
            }
        }

        return ans;
    }
};
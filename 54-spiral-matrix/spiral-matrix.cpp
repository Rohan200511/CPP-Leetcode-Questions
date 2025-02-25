class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
        int top = 0, bottom = row - 1;
        int left = 0, right = col - 1;
        
        while (left <= right && top <= bottom) {
            // Traverse from left to right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;  // Move down

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;  // Move left

            // Traverse from right to left, if there are rows remaining
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;  // Move up
            }

            // Traverse from bottom to top, if there are columns remaining
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;  // Move right
            }
        }
        
        return ans;
    }
};

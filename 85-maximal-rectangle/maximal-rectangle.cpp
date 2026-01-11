class Solution {
public:
    vector<int> NSL(vector<int>& h) {
        int n = h.size();
        vector<int> left(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return left;
    }

    vector<int> NSR(vector<int>& h) {
        int n = h.size();
        vector<int> right(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && h[st.top()] >= h[i])
                st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return right;
    }

    int largestHistogram(vector<int>& h) {
        int n = h.size();
        vector<int> left = NSL(h);
        vector<int> right = NSR(h);
        int maxA = 0;

        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxA = max(maxA, h[i] * width);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int r = matrix.size(), c = matrix[0].size();
        vector<int> height(c, 0);
        int ans = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, largestHistogram(height));
        }
        return ans;
    }
};

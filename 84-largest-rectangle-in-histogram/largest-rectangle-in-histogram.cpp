class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int element,nse,pse;
        int maxArea = 0;
        for(int i = 0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty()?-1:st.top();
                maxArea = max(maxArea,heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = n;
            element = st.top();
            st.pop();
            pse= st.empty() ? -1 : st.top();
            maxArea = max(maxArea , (nse - pse -1)*heights[element]);
        }
        return maxArea;
    }
};
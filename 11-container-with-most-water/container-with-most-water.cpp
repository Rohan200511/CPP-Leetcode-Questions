class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int area = INT_MIN;

        while(l < r){
            int width = r - l;
            int h = min(height[l] , height[r]);

            int ar = width * h;

            area = max(area , ar);

            (height[l] < height[r]) ? l++ : r--;
        }
        return area;
    }
};
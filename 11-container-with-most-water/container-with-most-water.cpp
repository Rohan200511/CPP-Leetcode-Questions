class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp = 0 , rp = height.size() - 1;
        int maxArea = INT_MIN;

        while(lp < rp){
            int width = rp - lp;
            int h = min(height[lp] , height[rp]);
            maxArea = max(maxArea , width * h);

            height[lp] < height[rp] ? lp++ : rp--;
        }
        return maxArea;
    }
};
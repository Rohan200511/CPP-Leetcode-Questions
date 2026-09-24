class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int ans = INT_MIN;

        int i = 0 , j = n - 1;

        while(i < j){
            int width = j - i;
            int heig = min(height[i] , height[j]);

            int area = width * heig;

            ans = max(ans , area);

            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};
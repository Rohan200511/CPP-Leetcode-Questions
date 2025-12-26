class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penalty(n + 1);

        int totalY = count(customers.begin(), customers.end(), 'Y');

        int nCount = 0, yCount = totalY;

        penalty[0] = yCount;

        for (int i = 1; i <= n; i++) {
            if (customers[i - 1] == 'N') nCount++;
            else yCount--;
            penalty[i] = nCount + yCount;
        }

        return min_element(penalty.begin(), penalty.end()) - penalty.begin();
    }
};
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < heights.size() - 1; i++) {

            if (heights[i + 1] <= heights[i])
                continue;

            int val = heights[i + 1] - heights[i];

            if (ladders > 0) {
                pq.push(val);
                ladders--;
            }
            else{
                if(!pq.empty() && val > pq.top()) {
                    if (bricks < pq.top())
                        return i;

                    bricks -= pq.top();
                    pq.pop();
                    pq.push(val);
                }
                else{
                    if (bricks < val)
                        return i;

                    bricks -= val;
                }
            }
        }

        return heights.size() - 1;
    }
};
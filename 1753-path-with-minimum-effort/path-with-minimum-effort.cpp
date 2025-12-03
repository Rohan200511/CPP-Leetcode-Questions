class Solution {
public:

    typedef pair<int , pair<int , int>> P;
    vector<vector<int>>directions = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>result(n , vector<int>(m , INT_MAX));

        priority_queue<P , vector<P> , greater<P>>pq;

        auto isSafe = [&](int x , int y){
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        result[0][0] = 0;
        pq.push({0 , {0 , 0}});

        while(pq.size()){
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();
            int x = coord.first;
            int y = coord.second;

            if(x == n-1 && y == m-1) return diff;

            for(auto& dir : directions){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(isSafe(nx , ny)){
                    int absDiff = abs(heights[x][y] - heights[nx][ny]);
                    int maxDiff = max(diff , absDiff);

                    if(result[nx][ny] > maxDiff){
                        result[nx][ny] = maxDiff;
                        pq.push({maxDiff , {nx , ny}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};
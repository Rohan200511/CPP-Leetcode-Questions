class Solution {
public:

    typedef pair<int , pair<int , int>> P;
    vector<vector<int>>directions = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1} , {-1 , -1} , {-1 , 1} , {1 , -1} , {1 , 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n == 0 || m == 0 || grid[0][0] != 0) return -1;

        auto isSafe = [&](int i , int j){
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        vector<vector<int>>res(n , vector<int>(m , INT_MAX));

        priority_queue<P , vector<P> , greater<P>>pq;

        pq.push({0 , {0 , 0}});
        res[0][0] = 0;
        grid[0][0] = 1;

        while(pq.size()){
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(auto& dir : directions){
                int nr = i + dir[0];
                int nc = j + dir[1];

                int dist = 1;

                if(isSafe(nr , nc) && grid[nr][nc] == 0 && d + dist < res[nr][nc]){
                    pq.push({d + dist , {nr , nc}});
                    res[nr][nc] = d + dist;
                }
            }
        }
        if(res[n-1][m-1] == INT_MAX) return -1;

        return res[n-1][m-1] + 1;
    }
};
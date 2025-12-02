class Solution {
public:

    vector<vector<int>>directions = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1} , {-1 , -1} , {-1 , 1} , {1 , -1} , {1 , 1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(n == 0 || m == 0 || grid[0][0] != 0) return -1;

        auto isSafe = [&](int i , int j){
            return i >= 0 && i < n && j >= 0 && j < m;
        };

        queue<pair<int , int>>q;
        q.push({0,0});
        grid[0][0] = 1;

        int level = 0;

        while(q.size()){
            int size = q.size();

            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                if(i == n-1 && j == m-1) return level+1;

                for(auto& dir : directions){
                    int nr = i + dir[0];
                    int nc = j + dir[1];

                    if(isSafe(nr , nc) && grid[nr][nc] == 0){
                        q.push({nr , nc});
                        grid[nr][nc] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};
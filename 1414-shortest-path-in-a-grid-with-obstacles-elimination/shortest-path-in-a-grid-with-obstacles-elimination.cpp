class Solution {
public:

    using T = tuple<int , int , int>;

    vector<vector<int>>dirs = {{0 , 1} , {1 , 0} , {-1 , 0} , {0 , -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        queue<T>q;
        q.push({0 , 0 , k});

        vector<vector<int>>vis(n , vector<int>(m , -1));
        vis[0][0] = k;

        int steps = 0;

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [r , c , kk] = q.front();
                q.pop();

                if(r == n - 1 && c == m - 1) return steps;

                for(auto& dir : dirs){
                    int nr = dir[0] + r;
                    int nc = dir[1] + c;

                    if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                    int newK = kk - grid[nr][nc];

                    if(vis[nr][nc] >= newK || newK < 0) continue;

                    vis[nr][nc] = newK;
                    q.push({nr , nc , newK});
                }

            }
            steps++;
        }
        return -1;
    }
};
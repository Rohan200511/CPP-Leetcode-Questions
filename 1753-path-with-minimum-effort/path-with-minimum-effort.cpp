class Solution {
public:

    using T = tuple<int , int , int>;

    vector<vector<int>>dirs = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<T , vector<T> , greater<T>>pq;
        pq.push({0 , 0 , 0});

        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        dist[0][0] = 0;

        while(!pq.empty()){
            auto [effort , r , c] = pq.top();
            pq.pop();

            if(dist[r][c] < effort) continue;

            for(auto& dir : dirs){
                int nr = dir[0] + r;
                int nc = dir[1] + c;

                if(nr >= n || nc >= m || nr < 0 || nc < 0) continue;

                int ne = max(effort , abs(heights[nr][nc] - heights[r][c]));

                if(dist[nr][nc] > ne){
                    dist[nr][nc] = ne;
                    pq.push({ne , nr , nc});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
class Solution {
public:

    vector<vector<int>>dirs = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

    bool canReach(vector<vector<int>>& heights , int n , int m , int limit){

        queue<pair<int , int>>q;
        vector<vector<bool>>vis(n , vector<bool>(m , false));
        q.push({0 , 0});
        vis[0][0] = true;

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            if(r == n - 1 && c == m - 1) return true;

            for(auto& dir : dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                
                int diff = abs(heights[r][c] - heights[nr][nc]);

                if(!vis[nr][nc] && diff <= limit){
                    vis[nr][nc] = true;
                    q.push({nr , nc});
                }
            }

        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int left = 0;
        int right = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                right = max(right , heights[i][j]);
            }
        }

        int ans = right;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(canReach(heights , n , m , mid)){
                ans = mid;
                right = mid - 1;
            }
            else left = mid + 1;
        }
        return ans;
    }
};
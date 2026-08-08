class Solution {
public:

    vector<vector<int>>dirs = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n , vector<int>(m , -1));

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    q.push({i , j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto& dir : dirs){
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1){
                    q.push({nx , ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        return dist;
    }
};
class Solution {
public:

    int bfs(vector<vector<int>>& forest , pair<int,int>& target , pair<int,int>& curr){
        int m = forest.size();
        int n = forest[0].size();

        vector<vector<bool>>vis(m , vector<bool>(n , false));
        queue<pair<int,int>>q;

        q.push(curr);
        vis[curr.first][curr.second] = true;

        int steps = 0;
        int dirs[4][2] = {{1,0} , {-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [x , y] = q.front();
                q.pop();

                if(x == target.first && y == target.second){
                    return steps;
                }

                for(auto& d : dirs){
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx < m && ny < n && nx >= 0 && ny >= 0 && forest[nx][ny] != 0 && !vis[nx][ny]){
                        vis[nx][ny] = true;
                        q.push({nx,ny});
                    }
                }
            }
            steps++;
        }
        return -1;
    }

    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();

        vector<pair<int , pair<int,int>>>trees;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(forest[i][j] > 1)trees.push_back({forest[i][j] , {i , j}});
            }
        }

        sort(begin(trees) , end(trees));

        int ans = 0;

        pair<int,int> curr = {0,0};

        for(auto& it : trees){
            auto target = it.second;

            int steps = bfs(forest , target , curr);
            
            if(steps == -1) return -1;

            ans += steps;

            curr = target;
        }
        return ans;
    }
};
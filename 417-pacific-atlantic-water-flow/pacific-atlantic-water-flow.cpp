class Solution {
public:

    int n , m;
    vector<vector<int>>directions = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};

    void dfs(vector<vector<int>>& heights , int i , int j , int prevValue , vector<vector<bool>>& vis){

        if(i < 0 || i >= n || j < 0 || j >= m) return;

        if(heights[i][j] < prevValue || vis[i][j] == true){
            return;
        }
        vis[i][j] = true;

        for(auto& dir : directions){
            int nr = i + dir[0];
            int nc = j + dir[1];

            dfs(heights , nr , nc , heights[i][j] , vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>>pVis(n , vector<bool>(m , false));
        vector<vector<bool>>aVis(n , vector<bool>(m , false));

        for(int i = 0 ; i < m ; i++){
            dfs(heights , 0 , i , INT_MIN , pVis);
            dfs(heights , n-1 , i , INT_MIN , aVis);
        }

        for(int j = 0 ; j < n ; j++){
            dfs(heights , j , 0 , INT_MIN , pVis);
            dfs(heights , j , m-1 , INT_MIN , aVis);
        }
        vector<vector<int>>ans;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(pVis[i][j] && aVis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
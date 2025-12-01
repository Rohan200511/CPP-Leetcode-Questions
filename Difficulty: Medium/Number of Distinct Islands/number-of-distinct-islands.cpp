// User function Template for C++

class Solution {
  public:
  
    int n , m;
    vector<vector<int>>dir = {{1 , 0} , {0 , 1} , {-1 , 0} , {0 , -1}};
    
    void dfs(int row , int col , vector<vector<bool>>& vis , vector<pair<int , int>>& vec , vector<vector<int>>& grid , int baser , int basec){
        
        vis[row][col] = true;
        vec.push_back({baser - row , basec - col});
        
        for(int i = 0 ; i < 4 ; i++){
            int nr = row + dir[i][0];
            int nc = col + dir[i][1];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == 1)
                    dfs(nr , nc , vis , vec , grid , baser , basec);
        }
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<bool>>vis(n , vector<bool>(m , false));
        
        set<vector<pair<int,int>>>st;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j]  && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i , j , vis , vec , grid , i , j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};

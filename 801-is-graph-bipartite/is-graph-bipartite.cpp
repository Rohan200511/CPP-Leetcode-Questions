class Solution {
public:

    bool dfs(vector<vector<int>>& graph , int curr , vector<int>& color , int currColor){

        color[curr] = currColor;

        for(int v : graph[curr]){
            if(color[v] == currColor) return false;

            if(color[v] == -1){
                int colorV = 1 - currColor;
                if(dfs(graph , v , color , colorV) == false) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size() , -1);

        for(int i = 0 ; i < graph.size() ; i++){
            if(color[i] == -1){
                if(dfs(graph , i , color , 1) == false) return false;
            }
        }
        return true;
    }
};
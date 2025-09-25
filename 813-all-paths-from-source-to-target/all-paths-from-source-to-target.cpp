class Solution {
public:

    void dfs(vector<vector<int>>& graph , int n , int node ,vector<int>& path,vector<vector<int>> &ans){
        path.push_back(node);

        if(node == n-1){
            ans.push_back(path);
            return;
        } 
        else{
            for(int next : graph[node]){
                dfs(graph,n,next,path,ans);
                path.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = graph.size();
        dfs(graph,n,0,path,ans);
        return ans;
    }
};
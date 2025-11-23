class Solution {
public:

    bool isCycle(int src , vector<bool>& vis , vector<bool>& recPath , vector<vector<int>>& prerequisites){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
             
            if(u == src){
                if(!vis[v]){
                    if(isCycle(v , vis , recPath , prerequisites)) return true;
                }
                else if(recPath[v]) return true;
            }
        }
        recPath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool>vis(n , false);
        vector<bool>recPath(n , false);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                if(isCycle(i , vis , recPath , prerequisites)) return false;
            }
        } 
        return true;
    }
};
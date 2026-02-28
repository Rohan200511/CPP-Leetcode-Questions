class Solution {
public:

    int result = -1;

    void dfs(int u , const vector<int>& edges , vector<bool>& vis , vector<bool>& isRec , vector<int>& count){
        vis[u] = true;
        isRec[u] = true;

        int v = edges[u];

        if(v != -1 && !vis[v]){
            count[v] = count[u] + 1;
            dfs(v , edges , vis , isRec , count);
        }
        else if(v != -1 && isRec[v]){
            result = max(result , count[u] - count[v] + 1);
        }
        isRec[u] = false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool>vis(n , false);
        vector<bool>isRec(n , false);
        vector<int>count(n , 1);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) dfs(i , edges , vis , isRec , count);
        }

        return result;
    }
};
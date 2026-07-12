class Solution {
public:
    int ans = -1;

    void dfs(int u , vector<bool>& vis , vector<bool>& recPath , vector<int>& edges , vector<int>& count){
        vis[u] = recPath[u] = true;

        int v = edges[u];

        if(v != -1 && !vis[v]){
            count[v] = count[u] + 1;
            dfs(v , vis , recPath , edges , count);
        }
        else if(v != -1 && recPath[v]){
            int temp = count[u] - count[v] + 1;

            ans = max(ans , temp);
        }
        recPath[u] = false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<bool>vis(n , false);
        vector<bool>recPath(n , false);
        vector<int>count(n , 0);

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]) dfs(i , vis , recPath , edges , count);
        }
        return ans;
    }
};
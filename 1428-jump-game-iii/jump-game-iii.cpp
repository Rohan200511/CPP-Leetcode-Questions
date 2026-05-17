class Solution {
public:
    int n;
    vector<bool>vis;

    bool dfs(vector<int>& arr , int ind){
        if(ind > n || ind < 0 || vis[ind]) return false;
        if(arr[ind] == 0) return true;

        vis[ind] = true;

        return dfs(arr , ind + arr[ind]) || dfs(arr , ind - arr[ind]);
    }

    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        vis.resize(n , false);
        return dfs(arr , start);
    }
};
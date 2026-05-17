class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int>q;
        vector<bool>vis(n , false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()){
            int ind = q.front();
            q.pop();

            if(arr[ind] == 0) return true;

            int frwd = ind + arr[ind];
            int bkwd = ind - arr[ind];

            if(frwd < n && !vis[frwd]){
                q.push(frwd);
                vis[frwd] = true;
            }

            if(bkwd >= 0 && !vis[bkwd]){
                q.push(bkwd);
                vis[bkwd] = true;
            }
        }
        return false;
    }
};
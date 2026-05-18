class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        if(n == 1) return 0;

        unordered_map<int , vector<int>>mp;

        for(int i = 0 ; i < n ; i++){
            mp[arr[i]].push_back(i);
        }

        int steps = 0;
        queue<int>q;
        vector<bool>vis(n , false);

        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int sz = q.size();

            for(int j = 0 ; j < sz ; j++){
                int ind = q.front();
                q.pop();

                if(ind == n - 1) return steps;

                if(ind + 1 < n && !vis[ind + 1]){
                    q.push(ind + 1);
                    vis[ind + 1] = true;
                }

                if(ind - 1 >= 0 && !vis[ind - 1]){
                    q.push(ind - 1);
                    vis[ind - 1] = true;
                }

                for(int next : mp[arr[ind]]){
                    if(!vis[next]){
                        q.push(next);
                        vis[next] = true;
                    }
                }
                mp[arr[ind]].clear();
            }
            steps++;
        }
        return steps;
    }
};
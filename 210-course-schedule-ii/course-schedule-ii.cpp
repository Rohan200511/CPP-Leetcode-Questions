class Solution {
public:

    bool isCycle(int src , vector<vector<int>>& prerequisites , vector<bool>& vis , vector<bool>& recPath){
        vis[src] = true;
        recPath[src] = true;

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src){
                if(!vis[v]){
                    if(isCycle(v , prerequisites , vis , recPath)) return true;
                }
                else if(recPath[v]) return true;
            }
        }
        recPath[src] = false;
        return false;
    }
    
    void topoSort(int src , vector<bool>& vis , stack<int>& st , vector<vector<int>>& prerequisites){
        vis[src] = true;

        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src){
                if(!vis[v]){
                    topoSort(v , vis , st , prerequisites);
                }
            }
        }
        st.push(src);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses , false);
        vector<bool>recPath(numCourses , false);
        vector<int>ans;


        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                if(isCycle(i , prerequisites , vis , recPath)) return ans;
            }
        }

        stack<int>st;
        vis.assign(numCourses , false);

        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i]){
                topoSort(i , vis , st , prerequisites);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
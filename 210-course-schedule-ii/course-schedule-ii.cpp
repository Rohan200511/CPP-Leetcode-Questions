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

    void topSort(int src , vector<bool>& vis , stack<int>& st , vector<vector<int>>& prerequisites){
        vis[src] = true;
        for(int i = 0 ; i < prerequisites.size() ; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            if(u == src){
                if(!vis[v]){
                    topSort(v , vis , st , prerequisites);
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
                if(isCycle(i , vis , recPath , prerequisites))
                return ans;
            }
        }

        stack<int>st;
        vis.assign(numCourses , false);
        
        for(int i = 0 ; i < numCourses ; i++){
            if(!vis[i])
                topSort(i , vis , st , prerequisites);
        }

        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        stack<int>st;
        
        for(int i = 0 ; i < n ; i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(mat[a][b] == 1) st.push(b);
            else st.push(a);
        }
        
        int candidate = st.top(); st.pop();
        
        for(int i = 0 ; i < n ; i++){
            if(i != candidate){
                if(mat[i][candidate] == 0 || mat[candidate][i] == 1) return -1;
            }
        }
        return candidate;
    }
};
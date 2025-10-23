class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int>st;
        
        int n = mat.size();
        
        for(int i = 0 ; i < n ; i++) st.push(i);
        
        while(st.size() > 1){
            int i = st.top(); st.pop();
            int j = st.top(); st.pop();
            
            if(mat[i][j] == 1) st.push(j);
            else st.push(i);
        }
        
        int celeb = st.top();
        
        for(int i = 0 ; i < n ; i++){
            
            if((i != celeb) && (mat[i][celeb] == 0 || mat[celeb][i] == 1)) return -1;
        }
        
        return celeb;
    }
};
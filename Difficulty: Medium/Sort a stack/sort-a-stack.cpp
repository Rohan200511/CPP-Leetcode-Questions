class Solution {
  public:
    
    void InsertatCP(stack<int>& st , int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }
        
        int top = st.top();
        st.pop();
        InsertatCP(st , x);
        st.push(top);
    }
  
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int ele = st.top();
        st.pop();
        
        sortStack(st);
        InsertatCP(st , ele);
    }
};

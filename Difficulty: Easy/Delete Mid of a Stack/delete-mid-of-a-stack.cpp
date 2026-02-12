class Solution {
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here..
        int n = s.size();
        int mid = n / 2;
        stack<int>temp;
        
        for(int i = 0 ; i <= mid ; i++){
            temp.push(s.top());
            s.pop();
        }
        temp.pop();
        
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
};
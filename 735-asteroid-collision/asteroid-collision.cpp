class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;

        for(auto &a : asteroids){
            while(!st.empty() && st.top() > 0 && a < 0){
                int sum = st.top() + a;

                if(sum < 0) st.pop();

                else if(sum > 0) a = 0;

                else{
                    st.pop();
                    a = 0;
                }
            }

            if(a != 0) st.push(a);
        }
        int s = st.size();
        vector<int> ans(s);
        int i = s - 1;

        while(!st.empty()){
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};
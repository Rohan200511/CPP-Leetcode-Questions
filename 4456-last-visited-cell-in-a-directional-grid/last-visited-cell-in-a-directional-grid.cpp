class Solution {
public:

    bool isValid(int n , int m , int r , int c){
        if(r >= n || r < 0 || c < 0 || c >= m)return false;
        return true;
    }

    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int currR = 0 , currC = 0;

        set<pair<int , int>>st;
        
        st.insert({0 , 0});

        
        while (true) {
            char ch = grid[currR][currC];

            int newR = currR;
            int newC = currC;

            if (ch == 'R') newC++;
            else if (ch == 'L') newC--;
            else if (ch == 'U') newR--;
            else if (ch == 'D') newR++;

            if (!isValid(n, m, newR, newC) || st.count({newR, newC})) {
                return {currR, currC};
            }

            currR = newR;
            currC = newC;
            st.insert({currR, currC});
        }
        return {currR , currC};
    }
};
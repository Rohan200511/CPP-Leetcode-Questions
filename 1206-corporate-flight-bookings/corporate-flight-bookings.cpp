class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n + 1 , 0);

        for(auto& it : bookings){
            int first = it[0] - 1;
            int last = it[1];

            int seats = it[2];

            ans[first] += seats;
            ans[last] -= seats;
        }
        
        for(int i = 1 ; i < ans.size() ; i++){
            ans[i] += ans[i - 1];
        }

        ans.resize(n);
        
        return ans;
    }
};
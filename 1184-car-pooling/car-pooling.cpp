class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int arr[1001] = {};

        for(auto& it : trips){
            int p = it[0];
            int from = it[1];
            int to = it[2];

            arr[from] += p;
            arr[to] -= p;
        }

        int curr = 0;

        for(int num : arr){
            curr += num;

            if(curr > capacity) return false;
        }

        return true;
    }
};
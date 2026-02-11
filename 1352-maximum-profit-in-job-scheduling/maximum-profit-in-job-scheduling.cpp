class Solution {
public:

    int n;
    vector<int>t;

    int getNextIndex(vector<vector<int>>& arr , int beg , int curr_end){
        int end = n - 1;

        int ans = n + 1;

        while(beg <= end){
            int mid = beg + ((end - beg) / 2);

            if(arr[mid][0] >= curr_end){
                ans = mid;
                end = mid - 1;
            }
            else beg = mid + 1;
        }
        return ans;
    }

    int solve(vector<vector<int>>& arr , int i){
        if(i >= n) return 0;
        
        if(t[i] != -1) return t[i];

        int next = getNextIndex(arr , i + 1 , arr[i][1]);
        int take = arr[i][2] + solve(arr , next);
        int not_take = solve(arr , i + 1);

        return t[i] = max(take , not_take);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n = startTime.size();

        vector<vector<int>>arr(n , vector<int>(3 , 0));

        for(int i = 0 ; i < n ; i++){
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        sort(arr.begin() , arr.end());

        t.assign(n+1 , -1);
        return solve(arr , 0);
    }
};
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();

        sort(arr.begin() , arr.end());
        int min_diff = INT_MAX;


        for(int i = 0 ; i < n-1 ; i++){
            min_diff = min(min_diff , abs(arr[i] - arr[i+1]));
        }

        vector<vector<int>>ans;

        for(int i = 0 ; i < n - 1 ; i++){
            if(abs(arr[i] - arr[i+1]) == min_diff) ans.push_back({arr[i] , arr[i+1]});
        }
        return ans;
    }
};
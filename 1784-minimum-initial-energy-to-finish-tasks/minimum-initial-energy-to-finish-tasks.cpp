class Solution {
public:

    bool isPossible(vector<vector<int>>& tasks , long long Energy){

        for(auto& task : tasks){
            int actual = task[0];
            int mini = task[1];

            if(mini > Energy) return false;

            Energy -= actual;
        }
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        sort(tasks.begin() , tasks.end() , [&](auto& a , auto& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        long long low = 0;
        long long end = 1e9;

        long long ans = 0;

        while(low <= end){
            long long mid = low + ((end - low) / 2);

            if(isPossible(tasks , mid)){
                ans = mid;
                end = mid - 1;
            }
            else low = mid + 1;
        }
        return (int)ans;
    }
};
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        sort(tasks.begin() , tasks.end() , [&](auto& a , auto& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        long long Energy = 0;
        long long ans = 0;

        for(auto& task : tasks){
            int actual = task[0];
            int mini = task[1];

            if(Energy < mini){
                ans += (mini - Energy);
                Energy = mini;
            }
            Energy -= actual;
        }
        return (int)ans;
    }
};
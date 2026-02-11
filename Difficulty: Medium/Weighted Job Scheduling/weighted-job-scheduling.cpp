class Solution {
  public:
    
    int n;
    
    vector<int>t;
    
    int nextIndex(vector<vector<int>> &jobs , int beg , int curr_end){
        int end = n - 1;
        
        int ans = n + 1;
        
        while(beg <= end){
            int mid = beg + ((end - beg) / 2);
            
            if(jobs[mid][0] >= curr_end){
                ans = mid;
                end = mid - 1;
            }
            else beg = mid + 1;
        }
        return ans;
    }
    
    int solve(vector<vector<int>> &jobs , int i){
        if(i >= n) return 0;
        
        if(t[i] != -1) return t[i];
        
        int next = nextIndex(jobs , i + 1 , jobs[i][1]);
        int take = jobs[i][2] + solve(jobs , next);
        int not_take = solve(jobs , i+1);
        
        return t[i] = max(take , not_take);
    }
    
    int maxProfit(vector<vector<int>> &jobs) {
        // code here
         n = jobs.size();
         
         sort(jobs.begin() , jobs.end());
         
         t.assign(n + 1 , -1);
         
         return solve(jobs , 0);
    }
};

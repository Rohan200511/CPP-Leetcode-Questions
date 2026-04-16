class Solution {
public:

    /*int getPos(vector<int>& temp , int target){
        int l = 0 , r = temp.size() - 1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(temp[mid] == target) return mid;
            else if(temp[mid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }*/

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();

        unordered_map<int , vector<int>>mp;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]].push_back(i);
        }

        vector<int>ans;

        for(int i = 0 ; i < queries.size() ; i++){
            int curr_idx = queries[i];

            vector<int>& temp = mp[nums[queries[i]]];

            if (temp.size() == 1) {
                ans.push_back(-1);
                continue;
            }

            int m = temp.size();

            //int pos = getPos(temp , curr_idx);

            int pos = lower_bound(temp.begin() , temp.end() , curr_idx) - temp.begin();

            int prev = temp[(pos - 1 + m) % m];
            int next = temp[(pos + 1) % m];

            int d1 = min(abs(curr_idx - prev) , n - abs(curr_idx - prev));
            int d2 = min(abs(curr_idx - next) , n - abs(curr_idx - next));

           ans.push_back(min(d1,d2));
        }
        return ans;
    }
};
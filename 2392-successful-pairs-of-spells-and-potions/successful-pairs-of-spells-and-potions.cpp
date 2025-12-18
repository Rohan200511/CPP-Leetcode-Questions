class Solution {
public:
    int n , m;

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        n = spells.size();
        m = potions.size();
        vector<int>ans(n);
        sort(potions.begin() , potions.end());

        for(int i = 0 ; i < n ; i++){
            int low =  0;
            int high = m-1;
            long long curr = spells[i];

            while(low <= high){
                int mid = low + ((high - low) / 2);
                long long currProduct =  (long long) curr * potions[mid];
                if(currProduct >= success) high = mid - 1;
                else low = mid + 1;
            }

            ans[i] = m - low;
        }
        return ans;
    }
};
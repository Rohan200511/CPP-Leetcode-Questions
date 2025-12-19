class Solution {
public:

    bool isPossible(vector<int>& bloomDay , int days , int m , int k){
        int count = 0;
        int noofB = 0;

        for(int i = 0 ; i < bloomDay.size() ; i++){
            if(bloomDay[i] <= days) count++;
            else{
                noofB += count / k;
                count = 0;
            }
        }
        noofB += count / k;
        return noofB >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin() , bloomDay.end());
        int high = *max_element(bloomDay.begin() , bloomDay.end());
        long long reqd = 1LL * m * 1LL * k;
        if(reqd > bloomDay.size()) return -1;

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(isPossible(bloomDay , mid , m , k)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
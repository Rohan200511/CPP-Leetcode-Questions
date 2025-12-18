class Solution {
public:

    long long timetaken(vector<int>& piles , int gTime){
        long long totaltime = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            totaltime += (piles[i] + gTime - 1LL) / gTime;
        }
        return totaltime;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin() , piles.end());

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(timetaken(piles , mid) <= h){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};
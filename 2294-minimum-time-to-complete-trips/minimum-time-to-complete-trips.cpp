class Solution {
public:

    long long nooftrips(vector<int>& time , long long giventime){
        long long int totaltrips = 0;

        for(auto& x : time){
            totaltrips += giventime / x;
        }
        return totaltrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;

        while(low < high){
            long long mid = low + ((high - low) / 2);

            long long trips = nooftrips(time , mid);

            if(trips >= totalTrips) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
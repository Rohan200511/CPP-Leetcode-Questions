class Solution {
public: 

    bool canRepair(vector<int>& ranks , int cars , long long time){
        long long total_car = 0;

        for(int& rank : ranks){
            total_car += (long long) sqrt((long double)time / rank);
            if (total_car >= cars) return true;
        }
        return total_car >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1LL * *min_element(ranks.begin() , ranks.end()) * cars * cars;

        while(low < high){
            long long mid = low + ((high - low) / 2);

            if(canRepair(ranks , cars , mid)){
                high = mid ;
            }
            else low = mid + 1;
        }
        return low;
    }
};
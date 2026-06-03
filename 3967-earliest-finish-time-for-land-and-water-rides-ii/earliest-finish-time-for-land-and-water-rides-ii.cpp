class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int EarlyLand = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            EarlyLand = min(EarlyLand , landStartTime[i] + landDuration[i]);
        }

        //land -> water
        int l2w = INT_MAX;
        for(int j = 0 ; j < m ; j++){
            int temp = max(EarlyLand , waterStartTime[j]);
            l2w = min(l2w , temp + waterDuration[j]);
        }

        int EarlyWater = INT_MAX;
        for(int i = 0 ; i < m ; i++){
            EarlyWater = min(EarlyWater , waterStartTime[i] + waterDuration[i]);
        }

        // water - > land

        int w2l = INT_MAX;
        for(int j = 0 ; j < n ; j++){
            int temp = max(EarlyWater , landStartTime[j]);
            w2l = min(w2l , temp + landDuration[j]);
        }

        return min(l2w , w2l);
    }
};
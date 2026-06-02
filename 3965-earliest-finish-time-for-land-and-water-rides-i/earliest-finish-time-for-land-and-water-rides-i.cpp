class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            int finishLand = landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.size(); j++) {
                int startWater = max(finishLand, waterStartTime[j]);
                int finishWater = startWater + waterDuration[j];
                ans = min(ans, finishWater);
            }
        }

        for (int j = 0; j < waterStartTime.size(); j++) {
            int finishWater = waterStartTime[j] + waterDuration[j];
            for (int i = 0; i < landStartTime.size(); i++) {
                int startLand = max(finishWater, landStartTime[i]);
                int finishLand = startLand + landDuration[i];
                ans = min(ans, finishLand);
            }
        }

        return ans;
    }
};
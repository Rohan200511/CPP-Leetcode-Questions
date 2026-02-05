class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int maxTime = 0;
        vector<vector<int>> vec;

        for(int i = 0 ; i < plantTime.size() && i < growTime.size() ; i++){
            vec.push_back({plantTime[i] , growTime[i]});
        }

        sort(vec.begin() , vec.end() , [](auto& a , auto& b){
            return a[1] > b[1];
        });

        int timeTill = 0;

        for(auto& it : vec){
            int pT = it[0];
            int gT = it[1];
            timeTill += pT;

            int bloomDay = gT + timeTill;

            maxTime = max(maxTime , bloomDay);
        }
        return maxTime;
    }
};
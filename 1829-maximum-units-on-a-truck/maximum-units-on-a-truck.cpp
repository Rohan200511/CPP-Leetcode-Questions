class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , [](vector<int>& a , vector<int>& b){
            return a[1] > b[1];
        });

        int units = 0;

        for(auto& it : boxTypes){
            if(truckSize >= it[0]){
                units += it[0] * it[1];
                truckSize -= it[0];
            }
            else if (truckSize > 0){
                units += truckSize * it[1];
                truckSize -= it[0];
            }
        }
        return units;
    }
};
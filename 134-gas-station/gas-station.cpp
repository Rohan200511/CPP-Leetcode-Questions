class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totGas = 0 , totCost = 0 , start = 0 , currgas = 0;

        for(int i = 0 ; i < n ; i++){
            totGas += gas[i];
            totCost += cost[i];

            currgas += gas[i] - cost[i];

            if(currgas < 0){
                start = i+1;
                currgas = 0;
            }
        }

        if(totGas < totCost) return -1;

        return start;
    }
};
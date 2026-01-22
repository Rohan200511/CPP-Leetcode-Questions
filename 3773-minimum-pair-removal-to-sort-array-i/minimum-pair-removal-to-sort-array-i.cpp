class Solution {
public:

    int minPair(vector<int> v){
        int minSum = INT_MAX;
        int pos = -1;
        for(int i = 0; i < v.size() - 1; i ++){
            if(v[i] + v[i + 1] < minSum){
                minSum = v[i] + v[i + 1];
                pos = i;
            }
        }
        return pos;
    }

    void merge(vector<int> &v, int pos){
        v[pos] += v[pos + 1];
        v.erase(v.begin() + pos + 1);
    }

    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();

        int ops = 0;
        while(!is_sorted(nums.begin() , nums.end())){
            merge(nums , minPair(nums));
            ops++;
        }
        return ops;
    }
};
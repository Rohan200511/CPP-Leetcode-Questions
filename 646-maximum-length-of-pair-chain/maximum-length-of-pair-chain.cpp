class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , [](auto& a , auto& b){
            return a[1] < b[1];
        });

        int len = 1;
        int last = pairs[0][1];

        for(int i = 1 ; i < pairs.size() ; i++){

            if(last < pairs[i][0]){
                len++;
                last = pairs[i][1];
            }
        }
        return len;
    }
};
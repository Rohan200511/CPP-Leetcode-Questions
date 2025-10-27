class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.empty()) return 0;

        int ans = 0 , prevC = 0;
        
        for(int i = 0 ; i < bank.size() ; i++){
            int count = 0;

            for(int j = 0 ; j < bank[i].size() ; j++) if(bank[i][j] == '1') count++;

            if(count > 0){
                ans += count * prevC;
                prevC = count;
            }
        }
        return ans;
    }
};
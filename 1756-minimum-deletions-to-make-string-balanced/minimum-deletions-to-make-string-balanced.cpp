class Solution {
public:
    int minimumDeletions(string s) {
        int ans= 0 ;
        int count_b = 0;

        for(auto& c : s){
            if(c == 'b'){
                count_b++;
            }
            else{
                if(count_b > 0){
                    ans++;
                    count_b--;
                }
            }
        }
        return ans;
    }
};
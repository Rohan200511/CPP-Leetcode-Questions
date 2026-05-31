class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin() , asteroids.end());

        long long currWeight = mass;

        for(int ast : asteroids){
            if(currWeight >= ast){
                currWeight += ast;
            }
            else return false;
        }
        return true;
    }
};
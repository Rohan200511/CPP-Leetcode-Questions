class Solution {
public:

    int n;

    bool solve(vector<int>& piles , int i , int j , int A , int B , bool turn){

        if(i > j){
            return A >= B;
        }

        if(turn){
            return solve(piles , i + 1 , j , A + piles[i] , B , !turn) ||
                    solve(piles , i , j - 1 , A + piles[j] , B , !turn);
        }

        else{
            return solve(piles , i + 1 , j , B + piles[i] , B , !turn) ||
                    solve(piles , i , j - 1 , B + piles[j] , B , !turn);
        }

    }

    bool stoneGame(vector<int>& piles) {
        n = piles.size();

        return solve(piles , 0 , n - 1 , 0 , 0 , true);
    }
};
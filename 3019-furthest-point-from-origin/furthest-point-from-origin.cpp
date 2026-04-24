class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int left = 0 , right = 0, blanks = 0;

        for(int i = 0 ; i < n ; i++){
            if(moves[i] == 'L')left++;
            else if(moves[i] == 'R')right++;
            else blanks++;
        }

        return abs(right - left) + blanks;
    }
};
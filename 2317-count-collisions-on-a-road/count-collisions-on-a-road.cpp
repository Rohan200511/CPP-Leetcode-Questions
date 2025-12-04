class Solution {
public:
    int countCollisions(string directions) {
        int l = 0;
        int r = directions.length() - 1;

        while(l < directions.length() && directions[l] == 'L') l++;
        while(r >= 0 && directions[r] == 'R') r--;

        if(l >= r )return 0;

        int col = 0;
        
        for( ; l <= r ; l++){

            if(directions[l] != 'S'){
                col++;
            }
        }
        return col;
    }
};
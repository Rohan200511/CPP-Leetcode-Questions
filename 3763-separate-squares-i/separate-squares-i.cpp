class Solution {
public: 

    bool check(double mid , vector<vector<int>>& squares , double total){
        double botarea = 0.0;

        for(auto& sq : squares){
            double x = sq[0];
            double bott_y = sq[1];
            double l = sq[2];

            double top_y = bott_y + l;

            if(mid > top_y){
                botarea += l * l;
            }
            else if(mid > bott_y){
                botarea += l * ((mid - bott_y));
            }
        }

        return botarea >= total / 2.0;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0.0;

        for(auto& it : squares){
            double x = it[0];
            double y = it[1];
            double l = it[2];

            total += (l*l);
            low = min(low , y);
            high = max(high , y+l);
        }
        double result = 0.0;

        while(high - low > 1e-5){
            double mid = low + ((high - low) / 2);

            result = mid;

            if(check(mid , squares , total)){
                high = mid;
            }
            else low = mid;
        }
        return result;
    }
};
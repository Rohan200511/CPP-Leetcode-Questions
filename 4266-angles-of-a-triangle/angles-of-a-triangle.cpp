class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        vector<double>ans;
        sort(sides.begin(),sides.end());
        
        int a = sides[0];
        int b = sides[1];
        int c = sides[2];

        if(a + b <= c || b + c <= a || c + a <= b) return ans;

        double res_a = acos((b*b + c*c - a*a) / (2.0*b*c));
        double ress_a = res_a * 180 / M_PI;

        double res_b = acos((a*a + c*c - b*b) / (2.0*a*c));
        double ress_b = (res_b * 180 )/ M_PI;

        double ress_c = 180 - (ress_a + ress_b);

        ans.push_back(ress_a);
        ans.push_back(ress_b);
        ans.push_back(ress_c);

        sort(ans.begin(),ans.end());

        return ans;
    }
};
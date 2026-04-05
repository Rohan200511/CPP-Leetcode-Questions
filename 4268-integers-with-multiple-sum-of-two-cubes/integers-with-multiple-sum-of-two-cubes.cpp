class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        vector<int>ans;
        unordered_map<long long,int>mp;
        for(int a = 1 ; a <= cbrt(n) + 2 ; a++){
            long long a3 = a*a*a;
            if(a3 > n) break;
            for(int b = a ; b <= cbrt(n) + 2 ; b++){
                long long sum = a3 + b * b * b;

                if(sum > n) break;
                mp[sum]++;
            }
        }

        for(auto it : mp){
            if(it.second > 1) ans.push_back(it.first);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};
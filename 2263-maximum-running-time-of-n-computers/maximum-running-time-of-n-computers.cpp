class Solution {
public:

    typedef long long ll;

    bool isPossible(int n , vector<int>& batteries , int time){
        ll target =(ll) n * time;

        for(int i = 0 ; i < batteries.size() ; i++){
            target -= min((ll)batteries[i] ,(ll) time);

            if(target <= 0) return true;
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        ll left = *min_element(batteries.begin() , batteries.end());
        ll right = accumulate(batteries.begin() , batteries.end() , 0LL);
        right /= n;
        ll result = 0;
        while(left <= right){
            ll mid = (left + right) / 2;

            if(isPossible(n , batteries , mid)){
                result = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }

        return result;
    }
};
class Solution {
public:
    int n;

    bool canArrive(vector<int>& dist , double hour , int speed){
        double totalTime = 0;

        for (int i = 0; i < n - 1; i++) {
            totalTime += (dist[i] + speed - 1) / speed;
            if (totalTime > hour) return false;
        }

        totalTime += (long double)dist[n - 1] / speed;

        return totalTime <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        n = dist.size();
        if(hour <= n-1) return -1;

        int low = 1 , high = 1e9;
        int ans = -1;

        while(low <= high){
            int mid = low + ((high - low) / 2);

            if(canArrive(dist , hour , mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
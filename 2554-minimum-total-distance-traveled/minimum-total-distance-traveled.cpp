class Solution {
public:
    
    vector<vector<long long>>dp;

    long long solve(vector<int>& robot, vector<vector<int>>& factory , int i , int j , int n , int m){
        
        if(i == n) return 0;
        if(j == m) return 1e15;

        if(dp[i][j] != -1) return dp[i][j];

        long long res = solve(robot , factory , i , j + 1 , n , m);

        long long distance = 0;
        long long Fpos = factory[j][0];
        long long limit = factory[j][1];

        for(int k = 0; k < limit && i + k < n ; k++){
            distance += abs(Fpos - robot[i + k]);

            res = min(res , distance + solve(robot , factory , i + k + 1 , j + 1 , n , m));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(robot) , end(robot));
        sort(begin(factory) , end(factory));

        int nofRobots = robot.size();
        int nofFactories = factory.size();

        dp.assign(nofRobots , vector<long long>(nofFactories , -1));

        return solve(robot , factory , 0 , 0 , nofRobots , nofFactories);
    }
};
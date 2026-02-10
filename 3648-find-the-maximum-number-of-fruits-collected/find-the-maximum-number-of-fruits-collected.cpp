class Solution {
public:

    vector<vector<int>>t;

    int collect1(int n , vector<vector<int>>& fruits){
        int total = 0;

        for(int i = 0 ; i < n ; i++){
            total += fruits[i][i];
        }

        return total;
    }

    int collect2(int i , int j , int n , vector<vector<int>>& fruits){

        if(i >= n || j < 0 || j >= n) return 0;
        if(i == n-1 && j == n-1) return 0;
        if(i > j || i == j) return 0;
        
        if(t[i][j] != -1) return t[i][j];

        int downLeft = fruits[i][j] + collect2(i+1 , j-1 , n , fruits);
        int down = fruits[i][j] + collect2(i+1 , j , n , fruits);
        int downRight = fruits[i][j] + collect2(i+1 , j+1 , n , fruits);

        return t[i][j] =  max({downLeft , down , downRight});
    }

    int collect3(int i , int j , int n , vector<vector<int>>& fruits){

        if(i >= n || i < 0 || j >= n) return 0;
        if(i == n-1 && j == n-1) return 0;
        if(i < j || i == j) return 0;

        if(t[i][j] != -1) return t[i][j];

        int upRight = fruits[i][j] + collect3(i-1 , j+1 , n , fruits);
        int right = fruits[i][j] + collect3(i , j+1 , n , fruits);
        int downRight = fruits[i][j] + collect3(i+1 , j+1 , n , fruits);

        return t[i][j] = max({upRight , right , downRight});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        t.assign(n , vector<int>(n , -1));

        int c1 = collect1(n , fruits);

        int c2 = collect2(0 , n-1 , n , fruits);

        int c3 = collect3(n-1 , 0 , n , fruits);

        return c1 + c2 + c3;
    }
};
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>color(n , 0);
        vector<int>ans;
        int count = 0;

        for(auto& it : queries){
            int coord = it[0];
            int col = it[1];

            if(color[coord] != 0 && coord > 0 && color[coord] == color[coord - 1]) count--;
            if(color[coord] != 0 && coord + 1 < n && color[coord] == color[coord + 1])count--;

            color[coord] = col;

            if(coord > 0 && color[coord] == color[coord - 1]) count++;
            if(coord + 1 < n && color[coord] == color[coord + 1])count++;

            ans.push_back(count);
        }
        return ans;
    }
};
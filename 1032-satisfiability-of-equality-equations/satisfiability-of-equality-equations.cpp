class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int i){
        if(parent[i] == i) return i;

        return parent[i] = find(parent[i]);
    }

    void unite(int x , int y){
        int xP = find(x);
        int yP = find(y);

        if(xP == yP) return;

        if(rank[xP] > rank[yP]) parent[yP] = xP;
        else if(rank[xP] < rank[yP]) parent[xP] = yP;
        else{
            parent[xP] = yP;
            rank[yP]++;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26 , 0);
        for(int i = 0 ; i < 26 ; i++){
            parent[i] = i;
        }

        for(string& s : equations){
            if(s[1] == '='){
                unite(s[0] - 'a' , s[3]-'a');
            }
        }

        for(string& s : equations){
            if(s[1] == '!'){
                char first = s[0];
                char second = s[3];

                int fP = find(first - 'a');
                int sP = find(second - 'a');

                if(fP == sP) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp = arr;
        sort(temp.begin() , temp.end());

        unordered_map<int , int>mp;

        int tRank = 1;

        for(int num : temp){
            if(!mp.count(num)){
                mp[num] = tRank++;
            }
        }

        for(int i = 0 ; i < arr.size() ; i++){
            arr[i] = mp[arr[i]];
        }

        return arr;

    }
};
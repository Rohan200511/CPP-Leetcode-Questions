class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());
        vector<vector<string>>res;
        string prefix = "";

        for(char c : searchWord){
            prefix += c;
            vector<string>suggestions;

            auto it = lower_bound(products.begin() , products.end() , prefix);

            for(int i = 0 ; i < 3 && (it + i) != products.end() ; i++){
                string can = *(it + i);

                if(can.find(prefix) == 0) suggestions.push_back(can);
                else break;
            }
            res.push_back(suggestions);
        }
        return res;
    }
};
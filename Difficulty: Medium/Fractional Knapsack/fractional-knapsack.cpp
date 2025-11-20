class Solution {
  public:
  struct Item{
      double ratio;
      int val;
      int weight;
  };
  
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        
        vector<Item>items(n);
        
        for(int i = 0 ; i < n ; i++){
            items[i] = {(double)val[i] / wt[i], val[i], wt[i]};
        }
        
        sort(items.begin() , items.end() , [&](auto& a , auto& b){
            return a.ratio > b.ratio;
        });
        
        double maxValue = 0;
        
        for(auto& it : items){
            if(capacity == 0) break;
            if(capacity >= it.weight){
                maxValue += it.val;
                capacity -= it.weight;
            }
            else{
                maxValue += it.ratio * capacity;
                break;
            }
        }
        return maxValue;
    }
};

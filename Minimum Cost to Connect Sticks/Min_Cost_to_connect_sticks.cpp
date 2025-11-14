#include<queue>
long long int minimumCostToConnectSticks(vector<int> &arr) {
     // Write your Code here.
     long long int cost = 0;
     priority_queue<long long int , vector<long long int> , greater<long long int>>pq;

     for(int num : arr){
          pq.push(num);
     }

     while(pq.size() > 1){
          int x = pq.top();
          pq.pop();
          int y = pq.top();
          pq.pop();

          cost += x + y;
          pq.push({x + y});
     }
     return cost;
}

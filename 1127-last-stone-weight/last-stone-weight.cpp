class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int& num : stones) pq.push(num);

        while(pq.size() > 1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();

            if(x == y) continue;
            if(x < y) y = y-x;
            pq.push(y);
        }
        if(pq.size() == 1) return pq.top();
        return 0;
    }
};
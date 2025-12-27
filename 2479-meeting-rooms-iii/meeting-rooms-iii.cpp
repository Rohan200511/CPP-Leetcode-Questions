class Solution {
public:
    typedef pair<long long , int>P;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();

        sort(meetings.begin() , meetings.end());
        vector<int>roomused(n , 0);
        
        priority_queue<int , vector<int> , greater<int>>free;
        priority_queue<P , vector<P> , greater<P>>busy;

        for(int room = 0 ; room < n ; room++) free.push(room);

        for(auto& meet : meetings){
            int start = meet[0];
            int end = meet[1];
            int dur = end - start;

            while(!busy.empty() && busy.top().first <= start){
                int room = busy.top().second;
                busy.pop();
                free.push(room);
            }

            if(!free.empty()){
                int room = free.top();
                free.pop();
                busy.push({end , room});
                roomused[room]++;
            }
            else{
                int room = busy.top().second;
                long long endT = busy.top().first;
                busy.pop();
                busy.push({endT + dur  , room});
                roomused[room]++;
            }
        }
        
        return max_element(roomused.begin() , roomused.end()) - roomused.begin();
    }
};
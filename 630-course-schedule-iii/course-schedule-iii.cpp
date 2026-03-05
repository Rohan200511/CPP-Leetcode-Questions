class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();

        sort(courses.begin() , courses.end() , [](auto& a , auto& b){
            return a[1] < b[1];
        });

        priority_queue<int>pq;

        int totalTime = 0;

        for(auto& course : courses){
            int duration = course[0];
            int last  = course[1];
            pq.push(duration);
            totalTime += duration;

            if(totalTime > last){
                totalTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
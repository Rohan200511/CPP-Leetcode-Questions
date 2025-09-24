class SpecialQueue {
private:
queue<int>q;
deque<int>minQ,maxQ;
public:

    void enqueue(int x) {
        // Insert element into the queue
        q.push(x);
        while(!minQ.empty() && minQ.back() > x)minQ.pop_back();
        minQ.push_back(x);
        while(!maxQ.empty() && maxQ.back() < x)maxQ.pop_back();
        maxQ.push_back(x);
    }

    void dequeue() {
        // Remove element from the queue
        if(q.front() == minQ.front()) minQ.pop_front();
        if(q.front() == maxQ.front()) maxQ.pop_front();
        q.pop();
    }

    int getFront() {
        // Get front element
        return q.front() ;
    }

    int getMin() {
        // Get minimum element
        return minQ.front();
    }

    int getMax() {
        // Get maximum element
        return maxQ.front();
    }
};
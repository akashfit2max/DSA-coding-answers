class MedianFinder {
public:
    // one min heap and one max heap
    priority_queue<int>q1;
    priority_queue<int,vector<int>,greater<int>>q2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q1.empty() || q1.top() > num) {
            q1.push(num);
        }
        else {
            q2.push(num);
        }

        if(q1.size() > q2.size() + 1) {
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size() > q1.size()+1) {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        if(q1.size() == q2.size()) {
            return (double)(q1.top() + q2.top())/2.0;
        }
        else {
            if(q1.size() > q2.size()) {
                return q1.top();
            }
            else {
                return q2.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
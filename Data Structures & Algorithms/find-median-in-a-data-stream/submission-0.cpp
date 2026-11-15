class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        
        // use do loop here cuz we always insert into maxHeap
        // and the number might belongs to larger half of input
        do {
            moveToMin();
        } while (sizeDiff() > 1);

        while (sizeDiff() < -1) {
            moveToMax();
        }
    }
    
    double findMedian() {
        auto diff = sizeDiff();
        if (diff == 0) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else if (diff > 0) {
            return maxHeap.top();
        }
        else {
            return minHeap.top();
        }
    }

private:
    // top is the largest, stores the smaller half of input
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // top is the smallest, stores the larger half of input
    priority_queue<int, vector<int>, greater<int>> minHeap;

    inline int sizeDiff() const {return (int)maxHeap.size() - minHeap.size();}

    inline void moveToMax() {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    inline void moveToMin() {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
};

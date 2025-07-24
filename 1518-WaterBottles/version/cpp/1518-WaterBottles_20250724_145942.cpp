// Last updated: 7/24/2025, 2:59:42 PM
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;

public:
    MedianFinder() {}

    void addNum(int num) {
        maxHeap.push(num);
        if (!maxHeap.empty() && !minHeap.empty() &&
            maxHeap.top() > minHeap.top()) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>maxHeap.size()+1){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else if(minHeap.size() < maxHeap.size()){
            return maxHeap.top();
        }
        return (minHeap.top()+maxHeap.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
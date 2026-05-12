class MedianFinder {
private:
    // Compare(a, b)
    // does A lose to B?  
    priority_queue<int, vector<int>, greater<int>> right_half; // min heap
    priority_queue<int, vector<int>, less<int>> left_half; // max heap
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (left_half.empty() || num <= left_half.top()) {
            left_half.push(num);
        } else {
            right_half.push(num);
        }

        // balance heaps
        if (abs((int)right_half.size() - (int)left_half.size()) > 1) {
            if (right_half.size() > left_half.size()) {
                // right_half bigger
                int top = right_half.top();
                right_half.pop();
                left_half.push(top);
            } else {
                // left_half bigger
                int top = left_half.top();
                left_half.pop();
                right_half.push(top);
            }
        }
    }
    
    double findMedian() {
        if (left_half.size() > right_half.size()) {
            return left_half.top();
        } else if (right_half.size() > left_half.size()) {
            return right_half.top();
        } else {
            return (right_half.top() + left_half.top()) / 2.0;
        }
    }
};

class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);

        if (!mins.empty() && mins.top() < val) {
            mins.push(mins.top());
        } else {
            mins.push(val);
        }
    }
    
    void pop() {
        s.pop();
        mins.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

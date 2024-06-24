class MinStack {
private:
    vector<pair<int,int>> stackVector;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minElement;
        if(stackVector.empty())
            minElement = val;
        else 
            minElement = min(val,stackVector[stackVector.size() - 1].second);
        stackVector.push_back({val,minElement});
    }
    
    void pop() {
        stackVector.pop_back();
    }
    
    int top() {
        return stackVector[stackVector.size() - 1].first;
    }
    
    int getMin() {
        return stackVector[stackVector.size() - 1].second;
    }
};

/**
 * Your MinstackVector object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
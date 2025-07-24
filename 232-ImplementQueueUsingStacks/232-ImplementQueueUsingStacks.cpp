// Last updated: 7/24/2025, 8:32:31 AM
class MyQueue {
private:
    stack <int> queue;
public:
    MyQueue() {
        ;
    }
    
    void push(int x) {
        queue.push(x);        
    }
    
    int pop() {
        stack <int> temp;
        while(!queue.empty())
        {
            temp.push(queue.top());
            queue.pop();
        }
        int res = temp.top();
        temp.pop();
        while(!temp.empty())
        {
            queue.push(temp.top());
            temp.pop();
        }
        return res;        
    }
    
    int peek() {
        stack <int> temp;
        while(!queue.empty())
        {
            temp.push(queue.top());
            queue.pop();
        }
        int res = temp.top();
        while(!temp.empty())
        {
            queue.push(temp.top());
            temp.pop();
        }
        return res;
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
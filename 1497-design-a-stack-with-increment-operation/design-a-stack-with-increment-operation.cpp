int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class CustomStack {
private: 
    vector<int> stack;
    vector<int> inc;
    int top;
public:
    CustomStack(int maxSize) {
        stack.resize(maxSize,0);
        inc.resize(maxSize,0);
        top = -1;
    }
    
    void push(int x) {
        if(top != stack.size()-1){
            top++;
            stack[top] = x;
            inc[top] = 0;
        }
    }
    
    int pop() {
        if(top != -1){
            int val = stack[top] + inc[top];
            if(top>0)
                inc[top - 1] += inc[top];
            top--;
            return val;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int index = min(k-1,top);
        if(index>=0)
            inc[index] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
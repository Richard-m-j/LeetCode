class CustomStack {
private: 
    vector<int> stack;
    int n;
    int top;
public:
    CustomStack(int maxSize) {
        n=maxSize;
        stack.resize(n,0);
        top = -1;
    }
    
    void push(int x) {
        if(top != n-1){
            top++;
            stack[top] = x;
        }
    }
    
    int pop() {
        if(top != -1)
            return stack[top--];
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,top+1);i++)
            stack[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
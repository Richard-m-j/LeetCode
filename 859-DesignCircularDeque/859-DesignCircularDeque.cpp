// Last updated: 7/24/2025, 8:29:04 AM
int speedUp = []{
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class MyCircularDeque {
private:
    vector<int> dq;
    int front, rear;
    int k;
public:
    MyCircularDeque(int k) {
        dq.resize(k, 0);
        front = -1;
        rear = -1;
        this->k = k;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            front = rear = 0;
            dq[front] = value;
            return true;
        }
        if (front == 0)
            front = k - 1;
        else
            front--;
        dq[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        if (isEmpty()) {
            front = rear = 0;
            dq[front] = value;
            return true;
        }
        rear = (rear + 1) % k;
        dq[rear] = value;
        return true;
    }

    bool deleteFront() {
        if(isEmpty())
            return false;
        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1)%k;
        return true;
    }

    bool deleteLast() {
        if(isEmpty())
            return false;
        if(front == rear)
            front = rear = -1;
        else
            if(rear == 0)
                rear = k-1;
            else
                rear--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return dq[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return dq[rear];
    }

    bool isEmpty() { return front == -1; }

    bool isFull() { return (rear + 1) % k == front; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
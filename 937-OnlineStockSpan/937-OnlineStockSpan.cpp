// Last updated: 7/24/2025, 8:28:47 AM
int speedUp = [] {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();
class StockSpanner {
private:
    stack<pair<int, int>> stack;

public:
    StockSpanner() {}

    int next(int price) {
        int res = 1;
        while (!stack.empty() && stack.top().first <= price) {
            res += stack.top().second;
            stack.pop();
        }
        stack.push({price, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
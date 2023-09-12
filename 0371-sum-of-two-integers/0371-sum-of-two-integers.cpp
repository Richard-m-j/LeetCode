class Solution {
public:
    int getSum(int a, int b) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        while(b)
        {
            int c = a & b;
            a = a ^ b;
            b = c << 1;
        }
        return a;
    }
};
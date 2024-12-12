class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<int> pq;
        for(int& gift: gifts)
            pq.push(gift);
        while(k && !pq.empty()){
            int g = pq.top();
            pq.pop();
            int sqroot = sqrt(g);
            pq.push(sqroot);
            k--;
        }
        long long res=0;
        while(!pq.empty()){
            int g = pq.top();
            pq.pop();
            res += g;
        }
        return res;
    }
};
// Last updated: 7/24/2025, 8:27:38 AM
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string res = "";
        while (!pq.empty()) {
            pair<int, char> large = pq.top();
            pq.pop();
            int l = res.length();
            if (l > 1 && (res[l - 1] == large.second) && (res[l - 2] == large.second)){
                    if(pq.empty())
                        break;
                    auto secondLarge = pq.top();
                    pq.pop();
                    pq.push(large);
                    large = secondLarge;
                }
            res += large.second;
            large.first--;
            if(large.first)
                pq.push(large);
            // cout<<large.first<<" "<<large.second<<endl;
        }
        return res;
    }
};
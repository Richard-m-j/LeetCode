class RecentCounter {
public:
    queue <int> requests;
    RecentCounter() {
        requests={};
    }
    
    int ping(int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int lb=t-3000;
        requests.push(t);
        while(!requests.empty() && requests.front()<lb)
            requests.pop();
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
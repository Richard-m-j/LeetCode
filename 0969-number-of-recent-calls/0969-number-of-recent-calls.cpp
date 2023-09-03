class RecentCounter {
public:
    vector <int> requests;
    RecentCounter() {
        requests={};
    }
    
    int ping(int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int lb=t-3000;
        requests.push_back(t);
        while(!requests.empty() && requests[0]<lb)
            requests.erase(requests.begin());
        return requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
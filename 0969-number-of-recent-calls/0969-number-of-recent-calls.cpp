class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        requests.push(t);
        while(requests.front()<t-3000)
            requests.pop();
        return requests.size();
    }
private:
    queue <int> requests;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
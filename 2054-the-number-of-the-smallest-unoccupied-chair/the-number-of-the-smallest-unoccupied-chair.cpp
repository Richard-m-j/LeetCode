class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
        int n = times.size();
        int ta = times[targetFriend][0];
        sort(times.begin(), times.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) 
                return a[1] < b[1];
            return a[0]<b[0];
            });
        priority_queue<int,vector<int>,greater<int>> freeChairs;
        for (int i = 0; i < n; i++) {
            int arrival = times[i][0];
            int leave = times[i][1];
            // int index = times[i][2];
            while (!heap.empty() && arrival >= (heap.top().first)){
                freeChairs.push(heap.top().second);
                heap.pop();
            }
            int chair;
            if (freeChairs.size()) {
                chair = freeChairs.top();
                freeChairs.pop();
            } else {
                chair = heap.size();
            }
            heap.push({leave, chair});
            if(arrival == ta)
                return chair;
        }
        return -1;
    }
};
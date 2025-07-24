// Last updated: 7/24/2025, 8:29:34 AM
class MyCalendar {
private:
    map<int,int> mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = mp.upper_bound(start);
        if(it == mp.end()||it->second >= end){
            mp[end] = start;
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
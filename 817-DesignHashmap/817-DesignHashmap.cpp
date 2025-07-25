// Last updated: 7/24/2025, 8:29:06 AM
class MyHashMap {
vector<int> mp;
public:
    MyHashMap() {
        mp.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        mp[key] = value; 
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1; 
        
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
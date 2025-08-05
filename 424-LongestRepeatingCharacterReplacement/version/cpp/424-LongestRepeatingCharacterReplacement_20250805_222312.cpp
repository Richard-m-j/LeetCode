// Last updated: 8/5/2025, 10:23:12 PM
class LRUCache {
private: 
    unordered_map<int, list<pair<int, int>>::iterator> mp; // Maps key to iterator of list
    list<pair<int, int>> cache; // Doubly linked list to store key-value pairs
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.count(key)){
            // Move the accessed key-value pair to the front (most recently used)
            cache.splice(cache.begin(), cache, mp[key]);
            return mp[key]->second; // Return the value associated with the key
        }
        return -1; // Key not found
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            // Update the value and move the pair to the front of the list
            mp[key]->second = value;
            cache.splice(cache.begin(), cache, mp[key]);
            return;
        }
        
        if(mp.size() == capacity){
            // Remove the least recently used item (back of the list)
            int least_recent_key = cache.back().first;
            cache.pop_back();
            mp.erase(least_recent_key);
        }
        
        // Insert the new key-value pair at the front of the list
        cache.emplace_front(key, value);
        mp[key] = cache.begin(); // Map the key to the list iterator
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
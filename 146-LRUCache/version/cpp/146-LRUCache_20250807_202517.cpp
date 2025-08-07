// Last updated: 8/7/2025, 8:25:17 PM
struct Listnode {
    int key;
    int val;
    Listnode *prev;
    Listnode *next;
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,Listnode*> mp; 
    void addNode(Listnode* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    void removeNode(Listnode* node){
        Listnode* prev = node->prev;
        Listnode* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    Listnode *head,*tail;
public:
    LRUCache(int capacity) {
        LRUCache::capacity = capacity;
        head = new Listnode();
        tail = new Listnode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            removeNode(mp[key]);
            addNode(mp[key]);
            return mp[key]->val;
        }
        return -1;        
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            removeNode(mp[key]);
            addNode(mp[key]);
            mp[key]->val = value;
            return;
        }
        mp[key] = new Listnode();
        mp[key]->val = value;
        mp[key]->key = key;
        addNode(mp[key]);
        if(mp.size()>capacity){
            Listnode *lastNode = tail->prev;
            removeNode(lastNode);
            mp.erase(lastNode->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
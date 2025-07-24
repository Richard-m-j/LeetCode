// Last updated: 7/24/2025, 8:31:27 AM
int speedUp = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
class RandomizedSet {
private:
    unordered_set <int> randomSet;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(randomSet.find(val) != randomSet.end())
            return false;
        randomSet.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(randomSet.find(val) == randomSet.end())
            return false;
        randomSet.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = rand() % randomSet.size();

        auto it = begin(randomSet);
        advance(it, n);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
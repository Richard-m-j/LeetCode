// Last updated: 7/24/2025, 8:24:26 AM
class SmallestInfiniteSet {
private:
    vector<int> infiniteSet;
    int small;
public:
    SmallestInfiniteSet() {
        for(int i=0;i<10001; i++)
            infiniteSet.push_back(1);
        small = 1;
    }
    
    int popSmallest() {
        int num = small;
        for(small++;small<1001 && !infiniteSet[small - 1];small++);
        infiniteSet[num -1] = 0;
        return num;
    }
    
    void addBack(int num) {
        infiniteSet[num -1] = 1;
        if(num<small)
            small = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
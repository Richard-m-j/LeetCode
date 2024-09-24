class Trie{
public:
    char c;
    Trie * links[10];
    Trie(char digit){
        c = digit;
        for (int i = 0; i < 10; i++) {
            links[i] = nullptr;
        }
    }
};
class Solution {
private:
    Trie * root;
    void insert(string num){
        Trie *ptr = root;
        for(int i=0;i<num.size();i++){
            if(ptr->links[num[i]-'0'] == nullptr)
                ptr->links[num[i]-'0'] = new Trie(num[i]);
            ptr = ptr->links[num[i]-'0'];
        }
    }
    int findDepth(string num){
        Trie *ptr = root;
        int depth = 0;
        for(int i=0;i<num.size();i++){
            if(ptr->links[num[i]-'0'] != nullptr){
                depth++;
                ptr = ptr->links[num[i]-'0'];
            }
            else
                break;
        }
        return depth;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        root = new Trie('#');
        for(int& num: arr1){
            insert(to_string(num));
        }
        int res = 0;
        for(int& num: arr2)
            res = max(res,findDepth(to_string(num)));
        return res;
    }
};
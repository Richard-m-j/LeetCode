// Last updated: 9/21/2025, 7:45:22 PM
class TrieNode{
    public:
        TrieNode* links[26];
        bool flag=false;
};
class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* ptr = root;
        for(char& c: word){
            if(!ptr->links[c-'a']){
                ptr->links[c-'a'] = new TrieNode();
            }
            ptr = ptr->links[c-'a'];
        }
        ptr->flag = true;
    }
    
    bool search(string word) {
        TrieNode* ptr = root;
        for(char& c: word){
            if(!ptr->links[c-'a']){
                return false;
            }
            ptr = ptr->links[c-'a'];
        }
        if(ptr->flag){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(char& c: prefix){
            if(!ptr->links[c-'a']){
                return false;
            }
            ptr = ptr->links[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
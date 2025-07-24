// Last updated: 7/24/2025, 8:27:24 AM
class TrieNode{
private:
    TrieNode *links[26];
    bool isWord = false;
public:
    TrieNode(){
        for(int i=0;i<26;i++)
            links[i] = NULL;
    }
    bool containsKey(char c){
        return links[c - 'a'];
    }
    void put(char c, TrieNode* node){
        links[c-'a'] = node;
    }
    TrieNode* get(char c){
        return links[c-'a'];
    }
    bool isEnd(){
        return isWord;
    }
    void setEnd(){
        isWord = true;
    }
    void dfs(vector<string>& currentList,string currentWord, TrieNode *node){
        if(currentList.size() == 3)
            return;
        if(node->isEnd()){
            currentList.push_back(currentWord);
        }
        for(int i=0;i<26;i++){
            if(node->links[i]){
                // cout<<currentWord<<"| ";
                dfs(currentList, currentWord + (char)(i + 'a'),node->links[i]);
            }
        }
    }
};
class Trie{
private:
    TrieNode* root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i]))
                node->put(word[i],new TrieNode());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    vector<string> startsWith(string word){
        TrieNode* node = root;
        // find containing node
        for(int i=0;i<word.length();i++){
            // cout<<word[i]<<" ";
            if(!node->containsKey(word[i]))
                return {};
            node = node->get(word[i]);
        }
        cout<<endl;
        //traverse the links for the first 3 words in dfs manner
        vector<string> res;
        node->dfs(res,word,node);
        return res;
    }
    
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //make trie
        Trie T;
        for(int i=0;i<products.size();i++)
            T.insert(products[i]);

        //search
        vector<vector<string>> res;
        string current = "";

        for(int i=0;i<searchWord.length();i++){
            current += searchWord[i];
            // cout<<current<<"- ";
            res.push_back(T.startsWith(current));
        }
        return res;
    }
};
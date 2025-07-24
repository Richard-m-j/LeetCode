// Last updated: 7/24/2025, 8:24:11 AM
class Trie{
public:
    char c;
    int score;
    Trie* links[26];
    Trie(char ch){
        c = ch;
        for(int i=0;i<26;i++)
            links[i] = nullptr;
        score = 0;
    }
};
class Solution {
private:
    Trie* root;
    void insert(string s){
        Trie* ptr = root;
        for(int i=0;i<s.length();i++){
            if(!ptr->links[s[i]-'a'])
                ptr->links[s[i]-'a'] = new Trie(s[i]);
            ptr = ptr->links[s[i]-'a'];
            ptr->score++;
            // cout<<ptr->c<<"- "<<ptr->score<<" ";
        }
        // cout<<"\n";
    }
    int find(string s){
        Trie* ptr = root;
        int res = 0;
        for(int i=0;i<s.length();i++){
            if(!ptr->links[s[i]-'a'])
                break;
            ptr = ptr->links[s[i]-'a'];
            res += ptr->score;
            // cout<<ptr->c<<"- "<<ptr->score<<" ";
        }
        // cout<<endl;
        return res;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new Trie('#');
        
        for(string& s: words)
            insert(s);
        vector<int> res;
        for(string& s: words)
            res.push_back(find(s));
        return res;
    }
};
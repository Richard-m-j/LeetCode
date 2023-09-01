class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length())
            return false;
        unordered_map <int,int> f1,f2;
        for(auto& i: word1)
            f1[i]++;

        for(auto& i: word2)
            if(f1.find(i)==f1.end())
                return false;
            else
                f2[i]++;

        for(auto& i: word1)
            if(f2.find(i)==f2.end())
                return false;
        
        vector <int> list1,list2;

        for(auto& i: f1)
            list1.push_back(i.second);
        for(auto& i: f2)
            list2.push_back(i.second);
        sort(list1.begin(),list1.end());
        sort(list2.begin(),list2.end());

        if(list1!=list2)
            return false;


               

        
        return true;
    }
};
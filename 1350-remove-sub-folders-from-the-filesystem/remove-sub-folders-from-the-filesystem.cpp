class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> folderSet;
        sort(folder.begin(),folder.end());
        for(string& s:folder){
            string curr = "";
            // cout<<s<<" ";
            bool isSubFolder = false;
            int i=0;
            while(i<s.length()){
                curr += s[i++];
                while(i<s.length() && s[i]!='/')
                    curr += s[i++];
                // cout<<curr<<" ";
                if(folderSet.count(curr)){
                    isSubFolder = true;
                    break;
                } 
            }
            if(!isSubFolder){
                // cout<<s<<" ";
                folderSet.insert(s);
            }
        }
        vector<string> res;
        for(auto& s:folderSet){
            res.push_back(s);
        }
        return res;
    }
};
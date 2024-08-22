class Solution {
private:
    vector<string> res;
    string digits;
    vector<string> keyboard = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        Solution::digits = digits;
        if(digits.size() == 0)
            return {};
        helper("");
        return res;
    }
    void helper(string s){
        if(s.size() == digits.size()){
            res.push_back(s);
            return;
        }
        string sequence = keyboard[digits[s.size()] - '0'];
        for(int i=0;i<sequence.size();i++){
            helper(s+sequence[i]);
        }
    }
};
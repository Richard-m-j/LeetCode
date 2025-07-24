// Last updated: 7/24/2025, 8:32:16 AM
class Solution {
private:
    vector<int> res;
    int operastion(char op,int a,int b){
        switch(op){
            case '+': return a+b;
            case '-': return a-b;
            case '*': return a*b;
            case '/': return a/b;
        }
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        bool isNum = true;
        for(int i=0;i<expression.length();i++){
            if(!isdigit(expression[i])){
                isNum = false;
                // cout<<expression[i]<<" ";
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));

                for(int& x: left)
                    for(int& y: right)
                        res.push_back(operastion(expression[i],x,y));   
            } 
        }
        if(isNum){
            // cout<<"num";
            res.push_back(stoi(expression));
        }
        return res;
    }
};
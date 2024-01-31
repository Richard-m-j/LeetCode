static const int speedUp = []{ios::sync_with_stdio(0);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> indexStack;
        int n = temperatures.size();
        vector<int> res(n,0);
        for (int i = n-1; i >= 0; i--) 
        {
            while(!indexStack.empty() && temperatures[indexStack.top()] <= temperatures[i])
                indexStack.pop();
            if(!indexStack.empty())
                res[i] = indexStack.top() - i;
            
            indexStack.push(i);
        }
        return res;
    }
};
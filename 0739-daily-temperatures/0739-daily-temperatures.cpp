class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector <int> res(n,0);
        for(int i=0; i<n-1;i++)
        {
            if(i>0 && temperatures[i] == temperatures[i-1])
            {
                res[i] = res[i-1]>0 ? res[i-1] - 1: 0;
                continue;
            }
            for(int j=i+1;j<n;j++)
                if(temperatures[i]<temperatures[j])
                {
                    res[i] = j - i; 
                    break;   
                }
        }
        return res;
    }
};
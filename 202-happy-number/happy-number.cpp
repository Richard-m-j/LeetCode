class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> occured;
        while(n!=1){
            if(occured.find(n)!=occured.end())
                return false;
            occured.insert(n);
            int newNumber = 0;
            while(n){
                int digit = n%10;
                newNumber+=digit*digit;
                n/=10;
            }
            n=newNumber;
        }
        return true;
    }
};
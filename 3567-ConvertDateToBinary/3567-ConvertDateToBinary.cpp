// Last updated: 7/24/2025, 8:22:17 AM
class Solution {
private:
    string intToBinary(int n){
        string res="";
        while(n){
            res = char((n&1)+'0') + res;
            n=n>>1;
        }
        return res;
    }
public:
    string convertDateToBinary(string date) {

        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));

        string binaryYear = intToBinary(year);
        string binaryMonth = intToBinary(month);
        string binaryDay = intToBinary(day);

        return  binaryYear + "-" + binaryMonth + "-" + binaryDay;
    }
};
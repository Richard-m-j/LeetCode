// Last updated: 7/24/2025, 8:30:08 AM
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {  
        int prev=0;
        int length= flowerbed.size();
        flowerbed.push_back(0);
        for(int i=0;i<length;)
        {
            if(flowerbed[i])
            {
                prev=flowerbed[i+1];
                i+=2;
            }
            else
                if(prev+flowerbed[i+1]==0)
                {
                    n--;
                    flowerbed[i]=1;
                    prev=flowerbed[i+1];
                    i+=2; 
                }
                else
                {    
                    prev=flowerbed[i];
                    i++;    
                }
            if(n<=0)
                return true;
        }
        return false;
        
    }
};
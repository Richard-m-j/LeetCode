class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {  
        int prev=0;
        int length= flowerbed.size();
        flowerbed.push_back(0);
     
        for(int i=0;i<length;i++)
        {
            if(!flowerbed[i])
                if(prev==0&&flowerbed[i+1]==0)
                {
                    n--;
                    flowerbed[i]=1;
                }    
            prev=flowerbed[i];    
        }
        if(n>0)
            return false;
        return true;
    }
};
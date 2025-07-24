// Last updated: 7/24/2025, 8:29:57 AM
class Solution {
public:
    string predictPartyVictory(string senate) {
        char active = 0;
        int activeCount=0;
        while(senate.length()>0)
        {
            bool changed=false;
            
            string nextRound="";
            for(char c: senate)
                if(!active)
                {
                    active=c;
                    nextRound+=c;
                    activeCount++;
                }
                else{
                    if(active==c)
                        nextRound+=c,activeCount++;
                    else
                    {
                        changed=true;
                        activeCount--;
                        if(activeCount==0)
                            active=0;

                    }
                }
            
            if(!changed)
                if(active=='R')
                    return "Radiant";
                else
                    return "Dire";
            senate=nextRound;            
        }
        return "";
    }
};
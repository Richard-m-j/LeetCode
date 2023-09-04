class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """ 
        queueR=[]
        queueD=[]
        l=len(senate)
        for i in range(l):
            if senate[i] == 'R':
                queueR+=[i]
            else:
                queueD+=[i]
        
        while queueR and queueD:
            indexR=queueR[0]
            indexD=queueD[0]
            queueR.pop(0)
            queueD.pop(0)            
            if indexR < indexD:
                queueR+=[indexR+l]
            else:
                queueD+=[indexD+l]
        
        if len(queueR)>len(queueD):
            return "Radiant"
        return "Dire"

        
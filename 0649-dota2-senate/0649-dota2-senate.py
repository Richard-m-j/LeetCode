class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """ 
        l = len(senate)
        banR = 0
        banD = 0
        
        while 'R' in senate and 'D' in senate:
            new_senate = []
            for senator in senate:
                if senator == 'R':
                    if banR > 0:
                        banR -= 1
                    else:
                        banD += 1
                        new_senate.append('R')
                else:  # senator == 'D'
                    if banD > 0:
                        banD -= 1
                    else:
                        banR += 1
                        new_senate.append('D')
            senate = new_senate
        
        return "Radiant" if 'R' in senate else "Dire"

# Last updated: 8/16/2025, 10:08:26 AM
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tmap = Counter(t)

        required = len(t)
        l=0
        minLen = -1
        start = -1
        for r in range(len(s)):
            if tmap.get(s[r],0) > 0:
                required -= 1
            tmap[s[r]] -= 1

            while required == 0:
                tmap[s[l]]+=1
                if minLen == -1 or minLen >  r-l+1:
                    minLen = r-l+1
                    start = l
                if tmap[s[l]] > 0:
                    required+=1
                l+=1
        if start == -1:
            return ""
        return s[start:start+minLen]

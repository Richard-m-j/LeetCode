# Last updated: 7/24/2025, 8:24:54 AM
class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        def validate(s: str, locked: str, op: str) -> bool:
            bal, wild = 0, 0
            for i in range(len(s)):
                if locked[i] == "1":
                    bal += 1 if s[i] == op else -1
                else:
                    wild += 1
                if wild + bal < 0:
                    return False
            return bal <= wild
        return len(s) % 2 == 0 and validate(s, locked, '(') and validate(s[::-1], locked[::-1], ')')
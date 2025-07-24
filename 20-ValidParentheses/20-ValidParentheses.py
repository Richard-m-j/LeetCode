# Last updated: 7/24/2025, 8:36:30 AM
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        compliment = {')':'(', '}':'{',']':'[' }
        for c in s:
            if c in compliment:
                if len(stack)  and compliment[c] == stack[-1]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(c)
        return len(stack) == 0
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        compliment = {')':'(', '}':'{',']':'[' }
        for c in s:
            if c in compliment:
                if len(stack):
                    if compliment[c] == stack[-1]:
                        stack.pop()
                    else:
                        return False
                else:
                    return False
            else:
                stack.append(c)
        return len(stack) == 0
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        left = ['(','{','[']
        right = [')','}',']']
        compliment = {')':'(', '}':'{',']':'[' }
        for c in s:
            if c in left:
                stack += [c]
            elif c in right:
                if len(stack):
                    if compliment[c] == stack[-1]:
                        stack = stack[:-1]
                    else:
                        return False
                else:
                    return False
        return len(stack) == 0
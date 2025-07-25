# Last updated: 7/24/2025, 8:28:49 AM
class Solution(object):
    def decodeAtIndex(self, s, k):
        total_length = 0

        for char in s:
            if char.isdigit():
                total_length *= int(char)
            else:
                total_length += 1
        
        for char in reversed(s):
            k %= total_length  
            if k == 0 and char.isalpha():
                return char
            
            if char.isdigit():
                total_length /= int(char)
            else:
                total_length -= 1

        return ""
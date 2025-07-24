# Last updated: 7/24/2025, 8:31:15 AM
class Solution(object):
    def decodeString(self, s):
        stack = []
        curr_num = 0
        curr_string = ''

        for c in s:
            if c == '[':
                stack.append((curr_string, curr_num))
                curr_num = 0
                curr_string = ''
            elif c == ']':
                prev_string, num = stack.pop()
                curr_string = prev_string + num * curr_string
            elif c.isdigit():
                curr_num = curr_num * 10 + int(c)
            else:
                curr_string += c

        return curr_string

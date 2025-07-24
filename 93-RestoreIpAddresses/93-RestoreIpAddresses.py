# Last updated: 7/24/2025, 8:34:53 AM
class Solution(object):
    def restoreIpAddresses(self, s):
        n = len(s)
        if n > 12 or n < 4:
            return []

        def is_valid(num_str):
            return 0 <= int(num_str) <= 255 and str(int(num_str)) == num_str

        ans = []

        for i in range(1, min(4, n - 2)):
            for j in range(i + 1, min(i + 4, n - 1)):
                for k in range(j + 1, min(j + 4, n)):
                    num1 = s[:i]
                    num2 = s[i:j]
                    num3 = s[j:k]
                    num4 = s[k:]

                    if is_valid(num1) and is_valid(num2) and is_valid(num3) and is_valid(num4):
                        ans.append("{}.{}.{}.{}".format(num1, num2, num3, num4))

        return ans

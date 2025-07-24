# Last updated: 7/24/2025, 8:23:15 AM
class Solution:
    def doesValidArrayExist(self, derived):
        return reduce(lambda x, y: x ^ y, derived, 0) == 0
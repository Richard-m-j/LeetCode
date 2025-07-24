# Last updated: 7/24/2025, 8:27:57 AM
class Solution(object):
    def defangIPaddr(self, address):
        """
        :type address: str
        :rtype: str
        """
        address = address.replace('.','[.]')
        return address
        
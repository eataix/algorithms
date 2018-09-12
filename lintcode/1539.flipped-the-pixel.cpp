class Solution:
    """
    @param Byte: 
    @return: return the answer after flipped
    """
    def flippedByte(self, Byte):
        for byte in Byte:
            left = 0
            right = len(byte) - 1
            
            while left <= right:
                byte[left], byte[right] = 1 - byte[right], 1 - byte[left]
                left += 1
                right -= 1
        return Byte

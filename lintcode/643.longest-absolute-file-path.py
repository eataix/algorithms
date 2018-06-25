class Solution:
    """
    @param input: an abstract file system
    @return: return the length of the longest absolute path to file
    """
    def lengthLongestPath(self, input_str):
        if len(input_str) == 0:
            return 0
        
        m = {0 :0}
        res = 0
        for s in input_str.split('\n'):
            depth = s.rfind('\t') + 1
            
            comp_len = len(s) - depth
            
            if '.' in s:
                res = max(res, m[depth] + comp_len)
            else:
                m[depth + 1] = m[depth] + 1 + comp_len
                
        return res

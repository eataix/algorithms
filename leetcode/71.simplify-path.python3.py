#
# [71] Simplify Path
#
# https://leetcode.com/problems/simplify-path/description/
#
# algorithms
# Medium (26.89%)
# Total Accepted:    122.9K
# Total Submissions: 456.8K
# Testcase Example:  '"/home/"'
#
# Given an absolute path for a file (Unix-style), simplify it.
#
# For example,
# path = "/home/", => "/home"
# path = "/a/./b/../../c/", => "/c"
#
# Corner Cases:
#
#
# Did you consider the case where path = "/../"?
# In this case, you should return "/".
# Another corner case is the path might contain multiple slashes '/' together,
# such as "/home//foo/".
# In this case, you should ignore redundant slashes and return "/home/foo".
#
#
#
class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        st = []
        for comp in path.split('/'):
            if comp == '' or comp == '.':
                continue
            if comp == '..' and len(st) > 0:
                st.pop()
            elif comp != '..':
                st.append(comp)

        if len(st) == 0:
            return '/'
        else:
            res = ''
            for s in st:
                res += '/' + s
            return res
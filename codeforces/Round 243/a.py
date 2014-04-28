#!/usr/bin/env python

[_, s] = [int(var) for var in raw_input().split()]

l = [int(var) for var in raw_input().split()]

if sum(l) - max(l) <= s:
    print "YES"
else:
    print "NO"

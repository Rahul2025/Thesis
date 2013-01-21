from math import fsum
def average(x):
    return fsum(x)/float(len(x)) if x else 0
print (average([3,1,4,1,5,9]))
print (average([1e20,3,1,4,1,5,9,-1e20]))
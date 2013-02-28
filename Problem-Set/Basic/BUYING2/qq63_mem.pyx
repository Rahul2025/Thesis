cases = int(raw_input())

for i in range(cases):
     n, x = map(int, raw_input().split())
     a = map(int, raw_input().split())
     minVal = min(a)
     total = sum(a)
     if(total % x >= minVal):
         print -1
     else:
         print total / x
# 10211 Maximum Subarray / Silver 4

import sys 
input = sys.stdin.readline

t = int(input())

for i in range(t):
  n = int(input())
  x = list(map(int, input().split()))
  
  result = [x[0]]
  
  for i in range(1, n):
    big = max(result[i-1] + x[i], x[i])
    result.append(big)
  
  print(max(result))
  
  
# 26069 붙임성 좋은 총총이 / Silver 4

import sys 
input = sys.stdin.readline

n = int(input())
dance = {'ChongChong'}

for i in range(1, n + 1):
  a, b = input().rstrip().split()
  
  if a in dance:
    dance.add(b)
    
  if b in dance:
    dance.add(a)
    
print(len(dance))
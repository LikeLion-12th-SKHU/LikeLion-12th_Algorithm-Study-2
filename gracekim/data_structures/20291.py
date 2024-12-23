# 20921 파일 정리 / Silver 3
import sys 
input = sys.stdin.readline

n = int(input())

dic = dict()
for _ in range(n):
  extend = (input().split('.'))[1]
  if not extend in dic:
    dic[extend] = 1
  else:
    dic[extend] += 1
    
    
sort_file = sorted(dic.items())

for key, value in sort_file:
  print(key.rstrip(), value)
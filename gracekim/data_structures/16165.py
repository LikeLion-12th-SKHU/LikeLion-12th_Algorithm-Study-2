import sys
input= sys.stdin.readline
from collections import defaultdict

N , M = map(int,input().split()) 
li = defaultdict(list) 
  
for _ in range(N):
    group = input().rstrip()
    num = int(input())
    for i in range(num):
        name = input().rstrip()
        li[group].append(name) 

li= dict(li) 
  
for _ in range(M):
    quiz_name = input().rstrip() 
    quiz_num = int(input())

    if quiz_num == 1:
        for key, values in li.items():
            if quiz_name in values:
                print(key)
                break
    elif quiz_num == 0:
        for key, values in li.items(): 
            if quiz_name in key:
                values.sort()
                for j in values:
                    print(j)
                break
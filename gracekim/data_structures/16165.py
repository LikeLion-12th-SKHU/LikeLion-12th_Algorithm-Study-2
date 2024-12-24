import sys
input= sys.stdin.readline
from collections import defaultdict

N , M = map(int,input().split()) #걸그룹수, 문제수
li = defaultdict(list) #default 값이 list인 딕셔너리
  
for _ in range(N):
    group = input().rstrip()
    num = int(input())
    for i in range(num):
        name = input().rstrip()
        li[group].append(name) #twice라는 그룹이 있다면, 그 그룹원의 이름을 append한다.

li= dict(li) #다시 dictionary로 바꿔준다. 
  
for _ in range(M):
    quiz_name = input().rstrip() #퀴즈 ( 걸그룹, 걸그룹멤버 둘중하나 )
    quiz_num = int(input())

    if quiz_num == 1: #1일 때는
        for key, values in li.items():
            if quiz_name in values: #해당 걸그룹 멤버를 value값으로 가지는 key를 출력한다.
                print(key)
                break
    elif quiz_num == 0:
        for key, values in li.items(): #해당 걸그룹 멤버들을 정렬해서 출력한다.
            if quiz_name in key:
                values.sort()
                for j in values:
                    print(j)
                break
# 1389 케빈 베이컨의 6단계 법칙 / Silver 1

import sys
from collections import deque

input = sys.stdin.readline

N, M = map(int, input().strip().split())

graph = [[] for _ in range(N+1)]

for _ in range(M):
  A, B = map(int, input().strip().split())
  graph[A].append(B)
  graph[B].append(A)

def BFS(graph, start):

  num = [0] * (N+1)

  ch[start] = 1

  # 시작 부분을 기준으로 시작
  Q = deque()
  Q.append(start)

  while Q:
    x = Q.popleft()
    for i in graph[x]:
      # 찾지 않은 친구인 경우에만
      if ch[i] == 0:
        # 한 번 거칠 때마다 + 1
        num[i] = num[x] + 1
        # 거쳤으니 찾았다고 표시
        ch[i] = 1
        # 또 해당 친구에서 다른 친구로 갈 수 있는 루트 찾기
        Q.append(i)

  return sum(num)

answer = []

for i in range(1, N+1):
  # 이미 찾았는지 확인할 리스트
  ch = [0] * (N+1)
  # i의 케빈 베이컨의 수 찾기
  answer.append(BFS(graph, i))

print(answer.index(min(answer)) + 1)
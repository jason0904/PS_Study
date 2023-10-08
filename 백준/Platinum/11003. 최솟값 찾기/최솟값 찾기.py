from collections import deque

n, k = map(int, input().split())
l = list(map(int, input().split()))

d = deque()
ans = list()

for i in range(n):
    while d and d[-1][0] > l[i]:
        d.pop()
    while d and d[0][1] < i - k + 1:
        d.popleft()
    d.append((l[i], i))
    print(d[0][0], end=" ")
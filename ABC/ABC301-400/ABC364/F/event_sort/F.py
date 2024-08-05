from sortedcontainers import SortedList

N, Q = map(int, input().split())
events = []
ans = 0
for _ in range(Q):
	L, R, C = map(int, input().split())
	events.append((L - 1, C, 0)) # 区間に入るイベント
	events.append((R - 1, C, 1)) # 区間から抜けるイベント
	ans += C
events.sort()
st = SortedList() # 今見ているインデックスでありえる C の集合
ind = 0
for i in range(N - 1):
	while ind < len(events) and events[ind][0] == i:
		if events[ind][2] == 0:
			st.add(events[ind][1])
		else:
			st.discard(events[ind][1])
		ind += 1
	if len(st) == 0:
		print(-1)
		exit()
	ans += st[0]
print(ans)
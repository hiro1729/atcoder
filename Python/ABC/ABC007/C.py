from queue import Queue
r, c = map(int, input().split())
sy, sx = map(int, input().split())
gy, gx = map(int, input().split())
s = [input() for _ in range(r)]
d = [[-1] * c for _ in range(r)]
d[sy - 1][sx - 1] = 0
q = Queue()
q.put((sy - 1, sx - 1))
while not q.empty():
    x, y = q.get()
    for i, j in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        if 0 <= x + i < r and 0 <= y + j < c and s[x + i][y + j] == '.' and d[x + i][y + j] == -1:
            q.put((x + i, y + j))
            d[x + i][y + j] = d[x][y] + 1
print(d[gy - 1][gx - 1])
r = [False] * 288
for _ in range(int(input())):
	s, e = input().split('-')
	sh = int(s[:2])
	sm = int(s[2:])
	eh = int(e[:2])
	em = int(e[2:])
	st = sh * 12 + sm // 5
	et = eh * 12 + (em + 4) // 5
	for i in range(st, et):
		r[i] = True
i = 0
while i < 288:
	j = i
	while j < 288 and r[j]:
		j += 1
	if i != j:
		sh = i // 12
		sm = i % 12 * 5
		eh = j // 12
		em = j % 12 * 5
		print(f"{sh:02}{sm:02}-{eh:02}{em:02}")
	i = j + 1
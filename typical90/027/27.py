n = int(input())
st = set()
for i in range(n):
    s = input()
    if s not in st:
        st.add(s)
        print(i + 1)
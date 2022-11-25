from collections import Counter
c = Counter(input() for _ in range(int(input())))
print(len(c.keys()))
print(*c.values())
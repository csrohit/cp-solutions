from collections import Counter

input()
shoes = Counter(map(int, input().split()))
earnings = 0
for _ in range(int(input())):
    size, price = map(int, input().split())
    if shoes[size] is not 0:
        earnings += price
        shoes[size] -= 1

print(earnings)
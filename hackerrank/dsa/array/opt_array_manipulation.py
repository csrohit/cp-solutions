
if __name__ == '__main__':
    n, m = map(int, input().split())
    arr = []
    for _ in range(m):
        a, b, k = map(int, input().split())
        arr.append((a-1, k))
        if b < n:
            arr.append(((b, -k)))
    arr = sorted(arr)
    ans = a = 0
    for pair in arr:
        a += pair[1]
        if ans < a :
            ans = a
    print(ans)
if __name__ == '__main__':
    n, m = map(int, input().split())
    arr = [0] * n
    for _ in range(m):
        a, b, k = map(int, input().split())
        arr[a-1] += k

        if b < len(arr):
            arr[b] -= k
        print(arr)
    ans = a = 0
    for i in arr:
        a = a + i
        if (ans < a): ans = a;
    print(ans)


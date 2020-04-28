def left_rotate(arr):
    first = arr[0]
    arr = arr[1:]
    arr.append(first)
    return arr


if __name__ == '__main__':
    n, d = map(int, input().split())
    arr = [int(i) for i in input().split()]
    for _ in range(d % n):
        arr = left_rotate(arr)
    print(*arr)

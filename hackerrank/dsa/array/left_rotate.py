def left_rotate(arr, d):
    items_rotated = arr[:d]
    nList = arr[d:]
    nList.extend(items_rotated)
    return nList

if __name__ == '__main__':
    n, d = map(int, input().split())
    arr = [int(i) for i in input().split()]
    arr = left_rotate(arr, d)
    print(*arr)

from collections import deque

if __name__ == '__main__':
    d = deque()
    for _ in range(int(input())):
        cmd, *args = input().split()
        getattr(d, cmd)(*args)
    print(*d)
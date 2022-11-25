from collections import deque
if __name__ == '__main__':

    for _ in range(int(input())):
        input()
        l = map(int, input().split())
        if max(l) not in (l[0], l[-1]):
            print('No')
        else:
            print('Yes')



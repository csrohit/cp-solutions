if __name__ == '__main__':
    n,x = map(int, input().split())
    print(*[sum(ls)/x for ls in zip(*[map(int, input().split()) for _ in range(x)])], sep='\n')

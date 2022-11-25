if __name__ == '__main__':
    n = int(input())    # number of squares on chocolate bar
    squares = list(map(int, input().split()))
    d, m = map(int, input().split())
    print(sum([1 for i in range(n-m) if sum(squares[i:i+m]) == d]))
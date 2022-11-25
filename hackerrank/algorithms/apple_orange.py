# Complete the countApplesAndOranges function below.
def countApplesAndOranges(s, t, a, b, apples, oranges):
    print(sum([1 for apple in apples if t >= apple+a >= s]))
    print(sum([1 for orange in oranges if s <= orange + b <= t]))

    pass

if __name__ == '__main__':
    s, t = map(int, input().split())
    a, b = map(int, input().split())
    m, n = map(int, input().split())
    apples = map(int, input().split())
    oranges = map(int, input().split())

    countApplesAndOranges(s, t, a, b, apples, oranges)
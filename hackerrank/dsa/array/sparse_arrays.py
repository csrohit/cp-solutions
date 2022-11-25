if __name__ == '__main__':
    strings = [input() for _ in range(int(input()))]
    queries = [input() for _ in range(int(input()))]
    for query in queries:
        print(strings.count(query))

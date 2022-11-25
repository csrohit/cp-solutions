if __name__ == '__main__':
    input()
    count = [0]*6
    for i in map(int, input().split()):
        count[i] +=1
    print(count.index(max(count)))
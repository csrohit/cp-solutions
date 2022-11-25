




if __name__ == '__main__':
    input()
    scores = list(map(int, input().split()))
    clow = chigh = 0
    high = low = scores[0]
    for i in scores:
        if i < low:
            clow+=1
            low = i
        elif i > high:
            chigh +=1
            high = i
    print(chigh, clow)


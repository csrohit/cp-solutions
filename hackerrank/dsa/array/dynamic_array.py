if __name__ == '__main__':
    seqList = []
    last_ans = 0
    N, q = map(int, input().split())

    # create seqList of N empty sequences
    for _ in range(N):
        seqList.append([])

    for _ in range(q):
        t, x, y = map(int, input().split())
        seqIndex = (x ^ last_ans) % N
        if t == 1:
            seqList[seqIndex].append(y)
        else:
            # size of seq at seqIndex
            s = len(seqList[seqIndex])
            # assign value of element y % size in seq to last_ans
            last_ans = seqList[seqIndex][y % s]
            print(last_ans)

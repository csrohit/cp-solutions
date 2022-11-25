if __name__ == '__main__':
    n, k = map(int, input().split())
    a = [int(x) for x in input().split()]
    mod = [0]*k
    for i in range(n):
        mod[a[i]%k]+=1

    count=0
    for i in range(int(k / 2) + 1):
        print(i)
        print(float(i))
        if i == 0:
            count += int(mod[0] * (mod[0] - 1) / 2)
        elif float(i) == (k / 2):
            count += int(mod[int(k / 2)] * (mod[int(k / 2)] - 1) / 2)
        else:
            count += int(mod[i] * mod[k - i])
    print(count)
from collections import OrderedDict

if __name__ == '__main__':
    d = OrderedDict()
    for _ in range(int(input())):
        item, space, price = input().rpartition(' ')
        d[item] = d.get(item, 0) + int(price)

    print(*[key + ' '+ str(value) for key, value in d.items()], sep='\n')
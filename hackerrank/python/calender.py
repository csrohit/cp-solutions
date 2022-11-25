import datetime
if __name__ == '__main__':
    m, d, y = map(int, input().split())
    print(datetime.date(y, m, d).strftime("%A"))